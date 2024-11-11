n,m=map(int,input().split())
inf=float("inf")

r=lambda n:range(n)
l=[[inf if i!=j else 0 for j in r(n)] for i in r(n)]
a,b,c=[None]*m,[None]*m,[None]*m

for i in r(m):
  a[i],b[i],c[i]=map(int,input().split())
  a[i]-=1
  b[i]-=1
  l[a[i]][b[i]]=c[i]
  l[b[i]][a[i]]=c[i]

for k in r(n):
  for i in r(n):
    for j in r(n):
      l[i][j]=min(l[i][j],l[i][k]+l[k][j])

ans=m
for i in r(m):
  f=False
  for j in r(n):
    if l[j][a[i]]+c[i]==l[j][b[i]]:
      f=True
  if f:ans-=1
print(ans)