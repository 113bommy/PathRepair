from itertools import permutations
n,m,r=map(int,input().split())
visit=list(map(int,input().split()))
dist=[[10**9]*n for i in range(n)]
for i in range(m):
  a,b,c=map(int,input().split())
  dist[a-1][b-1],dist[b-1][a-1]=c,c
for i in range(n):
  dist[i-1][i-1]=0
for i in range(n):
  for j in range(n):
    for k in range(n):
      dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k])
ans=10**9
check=permutations(visit)
for i in check:
  c=0
  for j in range(1,r):
    c+=dist[i[j-1]-1][i[j]-1]
  if c<ans:ans=c
print(ans)
