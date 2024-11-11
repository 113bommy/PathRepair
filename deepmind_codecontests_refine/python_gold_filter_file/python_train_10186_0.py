import itertools
N, M, R = map(int, input().split())
r = [int(x) - 1 for x in input().split()]
G = [[10 ** 7 for j in range(N)] for i in range(N)]
for i in range(N):
  G[i][i] = 0
for i in range(M):
  a, b, c = map(int, input().split())
  G[a - 1][b - 1] = c
  G[b - 1][a - 1] = c
def warshall_floyd(G):
  for k in range(N):
    for i in range(N):
      for j in range(N):
        G[i][j] = min(G[i][k] + G[k][j], G[i][j])
  return G
G = warshall_floyd(G)
D = 10 ** 8
for L in itertools.permutations(r):
  d = 0
  pre = L[0]
  for l in L[1:]:
    d += G[pre][l]
    pre = l
  D = min(d, D)
print(D)