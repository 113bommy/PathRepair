p=998244353
s=200005
f=[0]*s
g=[0]*s
f[0]=1
r=n=(int)(input())
for i in range(1,n):
 u,v=map(int,input().split())
 g[u]+=1
 g[v]+=1
 f[i]=(f[i-1]*i)%p
for u in range(1,n+1):
 r=(r*f[g[u]])%p
print(r)
