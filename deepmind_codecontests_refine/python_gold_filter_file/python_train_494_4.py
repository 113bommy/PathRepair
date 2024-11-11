n=int(input())
ab=[list(map(int,input().split())) for _ in range(n)]
from collections import defaultdict
from math import gcd
d=defaultdict(int)
for a,b in ab:
  if a==0 and b==0:
    d[(0,0)]+=1
  elif a==0:
    d[(1,0)]+=1
  elif b==0:
    d[(0,1)]+=1
  else:
    if a<0:
      a*=-1
      b*=-1
    g=gcd(a,b)
    d[(a//g,b//g)]+=1
mod=pow(10,9)+7
ans=1
keys=d.keys()
for k in keys:
  if k==(0,0):
    continue
  else:
    a,b=k
    x=b if b>0 else -b
    y=-a if b>0 else a
    k0=tuple([x,y])
    if k0 in d:
      ans*=pow(2,d[k],mod)-1+pow(2,d[k0],mod)-1+1
      ans%=mod
      d[k]=0
      d[k0]=0
    else:
      ans*=pow(2,d[(a,b)],mod)
      ans%=mod
ans+=d[(0,0)]
ans-=1
print(ans%mod)
