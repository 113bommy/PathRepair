import sys
import math
#print(input() )
cc,rc=map(int,input().split() )
rc=cc-rc
n=int(input() )
ret=0
for i in range(n):
  x,y,r=map(int,input().split() )
  dist=math.pow(x*x+y*y ,0.5)
#  print(dist,r,rc,cc,rc<=dist-r,rc<=dist+r<=cc)
  if rc<=dist-r<=cc and rc<=dist+r<=cc:
    ret+=1
print(ret)