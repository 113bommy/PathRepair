import sys
sys.setrecursionlimit(10**7)

n, m = map(int, input().split())
G = [[] for _ in range(n)]
for _ in range(m):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  G[a].append(b)
  G[b].append(a)
seen = [False]*n
def dfs(v, rep):
  seen[v] = True
  for nv in G[v]:
    if seen[nv]:
      continue
    rep.append(nv+1)
    dfs(nv, rep)
    break
  else:
    return rep
L1, L2 = [], []
dfs(0, L1)
dfs(0, L2)
ANS = L2[::-1] + [1] + L1
print(len(ANS))
print(*ANS)