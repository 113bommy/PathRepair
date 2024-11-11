import sys
input()
a,b=-1e11,1e11
for i in map(int,sys.stdin.readlines()):
  a=max(a,i-b)
  b=min(i,b)
print(a)