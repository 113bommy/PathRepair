from copy import deepcopy
INF=10**18
n=int(input())
a=[list(map(int,input().split())) for _ in range(n)]
c=deepcopy(a)
for k in range(n):
  for i in range(n):
    for j in range(n):
      c[i][j]=min(c[i][j],c[i][k]+c[k][j])
for i in range(n):
  for j in range(n):
    if a[i][j]!=c[i][j]:
      print(-1)
      exit()
ans=0
for i in range(n):
  for j in range(n):
    for k in range(n):
      if k==j or k==i:continue
      if c[i][j]==c[i][k]+c[k][j]:break
    else:ans+=c[i][j]
print(ans//2)