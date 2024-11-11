from itertools import permutations

N, M, R = map(int, input().split())
r = list(map(lambda x: int(x)-1, input().split()))

INF = 10**9
cost = [[INF]*N for _ in range(N)]
for _ in range(M):
  A, B, C = map(int, input().split())
  A -= 1
  B -= 1
  cost[A][B] = C
  cost[B][A] = C

for k in range(N):
  for i in range(N):
    for j in range(N):
      cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j])

ans = INF

for route in permutations(r):
  temp = 0
  for i in range(R-1):
    temp += cost[route[i]][route[i+1]]
  ans = min(ans, temp)

print(ans)