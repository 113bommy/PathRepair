import sys
sys.setrecursionlimit(10 ** 6)

N, M = map(int, input().split())
G = [[] for _ in range(N)]
for i in range(M):
  X,Y,Z = map(int, input().split())
  X -= 1
  Y -= 1
  G[X].append(Y)
  G[Y].append(X)
#print(G)

def dfs(u,v):
  for t in G[u]:
    #if t != v:
    if not Visited[t]:
      Visited[t] = True
      dfs(t,u)

Visited = [False for _ in range(N)]
ans = 0
for i in range(N):
  if not Visited[i]:
    Visited[i] = True
    ans += 1
    dfs(i,-1)
print(ans)
