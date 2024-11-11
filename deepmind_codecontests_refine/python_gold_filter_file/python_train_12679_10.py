n,m,l = map(int,input().split())
g = [[1<<30]*n for _ in range(n)]
for _ in range(m):
  a,b,c = map(int,input().split())
  g[a-1][b-1] = c
  g[b-1][a-1] = c
for i in range(n):
  g[i][i] = 0

def bell(g,n):
  for k in range(n):
    for i in range(n-1):
      for j in range(i+1,n):
        if g[i][j] > g[i][k] + g[k][j]:
          g[i][j] = g[i][k] + g[k][j]
          g[j][i] = g[i][j]
  return g

g = bell(g,n)
for i in range(n):
  for j in range(n):
    if i == j:
      g[i][j] = 0
    elif g[i][j] <= l:
      g[i][j] = 1
    else:
      g[i][j] = 1<<30
g = bell(g,n)

q = int(input())
for _ in range(q):
  s,t = map(int,input().split())
  if g[s-1][t-1]>>30:
    print(-1)
  else:
    print(g[s-1][t-1]-1)