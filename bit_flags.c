In C/C++, boolean variables consume 1 byte of memory. But all that is really needed is 1 bit: 0 means false, 1 means true. 
Many times, especially when dealing with graphics, rather than consuming a whole byte of memory for each boolean, several 
booleans are combined into a single byte of memory, where each boolean uses a different bit in the byte. These are then 
referred to as bit flags, or bit fields.


This is an example, using a 8-bit unsigned integer to store 8 flags:
 
    unsigned char options;

It is common to use larger fields, e.g. 32 bits, but I use 8 here for simplicity. The possible options, that can be turned 
on or off independently are declared in an enum like this (just using some arbitrary identifiers):

  enum Options {
    OpAutoRedraw    = 0x01,
    OpAntiAlias     = 0x02,
    OpPixelShader   = 0x04,
    OpVertexShader  = 0x08,
    OpFullscreen    = 0x10,
    OpDaylight      = 0x20
    // ...
  };

Note how each option is given a specific value. These values are carefully picked to match each bit in the 8-bit variable:

  // 0x01 ==   1 == "00000001"
  // 0x02 ==   2 == "00000010"
  // 0x04 ==   4 == "00000100"
  // 0x08 ==   8 == "00001000"
  // 0x10 ==  16 == "00010000"
  // 0x20 ==  32 == "00100000"
  // 0x40 ==  64 == "01000000"
  // 0x80 == 128 == "10000000" 

Now, each flag can be set independently, by using the bitwise OR operator:

  options = OpAutoRedraw | OpVertexShader | OpFullscreen;
  // options == 0x01 | 0x08 | 0x10 == "00011001" 

And can be tested using the bitwise AND operator:

  if (options & OpAutoRedraw) {} // true
  if (options & OpAntiAlias) {} // false 

