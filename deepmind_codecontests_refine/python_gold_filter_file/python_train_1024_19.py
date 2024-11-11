n,m=map(int,input().split())
g=[[10**9]*n for i in range(n)]
edges=[]
for i in range(m):
  u,v,c=map(int,input().split())
  g[u-1][v-1]=g[v-1][u-1]=c
  edges.append((u-1,v-1,c))
for k in range(n):
  for i in range(n):
    for j in range(n):
      g[i][j]=min(g[i][j],g[i][k]+g[k][j])
cnt=0
flag=False
for u,v,c in edges:
  if g[u][v]==c:
    cnt+=1
print(m-cnt)
