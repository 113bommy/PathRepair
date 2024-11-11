n,m=map(int,input().split())
INF=10**18
edge=[[INF]*n for i in range(n)]
s=[]
for i in range(m):
  u,v,c=map(int,input().split())
  edge[u-1][v-1]=edge[v-1][u-1]=c
  s.append((u-1,v-1,c))
for k in range(n):
  for i in range(n):
    for j in range(n):
      edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j])
cnt=0
for i,j,cost in s:
  if edge[i][j]==cost:
    cnt+=1
print(m-cnt)
