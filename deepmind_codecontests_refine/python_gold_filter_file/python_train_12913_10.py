import sys

data = sys.stdin.read()
for i in range(0x61,0x7b):
    print("%c : %d"  %(i,data.lower().count(chr(i))))
