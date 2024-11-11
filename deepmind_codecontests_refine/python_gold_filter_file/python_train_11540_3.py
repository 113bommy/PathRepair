N, M = map(int,input().split())

v = list(range(1,N+1))
edges = [[] for _ in range(N+1)]
for _ in range(M):
  a, b = map(int,input().split())
  edges[a] += [b]
  edges[b] += [a]

def dfs(v, e):
  for x in v:
    if(len(e[x]) == 1):
      t = e[x][0]
      e[x] = []
      e[t].remove(x)
      v.remove(x)
      return dfs(v, e)+1
  return 0

print(dfs(v, edges))