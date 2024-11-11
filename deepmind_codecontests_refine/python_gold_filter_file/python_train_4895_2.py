import sys
s=1e10;b=-s
input()
for r in map(int,sys.stdin):
 if b<r-s:b=r-s
 if s>r:s=r
print(b)
