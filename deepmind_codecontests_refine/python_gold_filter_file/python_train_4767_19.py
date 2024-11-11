import sys
input=sys.stdin.readline
k,q=map(int,input().split())
D=[int(i) for i in input().split()]
for _ in range(q):
  n,x,m=map(int,input().split())
  DD=[d%m for d in D]
  x%=m
  ans=n-1
  u,v=(n-1)//k,(n-1)%k
  z1,z2,r,s=0,0,0,0
  for i,d in enumerate(DD):
    s+=d
    if i<v:
      r+=d
      if d==0:
        z1+=1
        z2+=1
    elif d==0:
      z2+=1
  ans-=(z2*u+z1)+(x+s*u+r)//m
  print(ans)