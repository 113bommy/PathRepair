import heapq
N = int(input())
A = [[] for i in range(N)]
Q = []
for i in range(N):
  A[i] = [int(x) for x in input().split()]
  for j in range(i + 1, N):
    heapq.heappush(Q, [A[i][j], i, j])
G = [[10 ** 9 + 1 for j in range(N)] for i in range(N)]
for i in range(N):
  G[i][i] = 0
cnt = 0
while Q:
  [d, s, t] = heapq.heappop(Q)
  add = True
  for k in range(N):
    if d > G[s][k] + G[k][t]:
      break
    if d == G[s][k] + G[k][t]:
      add = False
  else:
    G[s][t] = d
    G[t][s] = d
    cnt += d if add else 0
    continue
  print(-1)
  break
else:
  print(cnt)