n, m, R = list(map(int, input().split()))
dist = [[float("INF") if i!=j else 0 for i in range(n)] for j in range(n)]
r = list(map(int, input().split()))
for i in range(m):
  a, b, c = list(map(int, input().split()))
  a, b = a-1, b-1
  dist[a][b] = c
  dist[b][a] = c
for k in range(n):
  for i in range(n):
    for j in range(n):
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

from itertools import permutations
ans = float("INF")
for e in permutations(r):
  cur = 0
  for i in range(R-1):
    cur += dist[e[i]-1][e[i+1]-1]
  ans = min(ans, cur)
print(ans)