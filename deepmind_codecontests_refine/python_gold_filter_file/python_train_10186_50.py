import itertools


N,M,R = map(int, input().split())
rs = list(map(int, input().split()))

INF = float("inf")
es = [[INF for _ in range(N)]  for _ in range(N)]
for i in range(N):
  es[i][i] = 0

for _ in range(M):
  a,b,c = map(int, input().split())
  es[a-1][b-1] = c
  es[b-1][a-1] = c



for k in range(N):
  for i in range(N):
    for j in range(N):
      es[i][j] = min(es[i][j], es[i][k] + es[k][j])

ans = INF
for route in itertools.permutations(rs):
  tmp = 0
  for a,b in zip(route, route[1:]):
    tmp += es[a-1][b-1]
  ans = min(ans, tmp)

print(ans)