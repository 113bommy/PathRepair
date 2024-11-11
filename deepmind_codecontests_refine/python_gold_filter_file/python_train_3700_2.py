from collections import *
n=int(input())
c,s,ans=Counter(),0,n-1
for x in map(int,input().split()):
  s+=x
  c[s]+=1
  ans=min(ans,n-c[s])
print(ans)