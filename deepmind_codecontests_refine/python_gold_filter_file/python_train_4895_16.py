import sys
b,s=-1e10,1e10
input()
for r in map(int,sys.stdin):
 if b<r-s:b=r-s
 if s>r:s=r
print(b)
