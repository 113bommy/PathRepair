n,m=map(int,input().split())
l=[list(map(int,input().split()))for i in range(m)]
dist=[[1<<29]*n for i in range(n)]
for i in range(n): dist[i][i]=0
for a in l:
  dist[a[0]-1][a[1]-1] = min(dist[a[0]-1][a[1]-1],a[2])
  dist[a[1]-1][a[0]-1] = min(dist[a[1]-1][a[0]-1],a[2])
# print(dist)
for k in range(n):
  for i in range(n):
    for j in range(n):
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
# 経路復元
ans=m
for a in l:
  flag=False
  for j in range(n): 
    if dist[j][a[0]-1]+a[2]==dist[j][a[1]-1]: flag=True
  if flag: ans-=1
print(ans)
