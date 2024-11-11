p=998244353
g=[0]*200005
r=n=(int)(input())
for i in range(1,n):
 u,v=map(int,input().split())
 g[u]+=1
 g[v]+=1
 r=r*g[u]*g[v]%p
print(r)