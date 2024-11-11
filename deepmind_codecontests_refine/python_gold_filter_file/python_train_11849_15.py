from itertools import groupby as gb
n,s=open(0)
n=int(n)
s=sorted(s[:-1])

ans=1
mod=10**9+7
for i,x in gb(s):
  ans=ans*(len(list(x))+1)%mod
print(ans-1)
