import sys
from collections import defaultdict as dd
from collections import deque as dq
input = sys.stdin.readline
N, K = map(int, input().split())
e = dd(list)
for _ in range(N - 1):
  a, b = map(int, input().split())
  e[a].append(b)
  e[b].append(a)
d = [[N for _ in range(N + 1)] for _ in range(N + 1)]
for s in range(1, N + 1):
  Q = dq([s])
  d[s][s] = 0
  while len(Q):
    p = Q.popleft()
    for q in e[p]:
      if d[s][q] > d[s][p] + 1:
        d[s][q] = d[s][p] + 1
        Q.append(q)
vis = set()
table = [[0] * (N + 1) for _ in range(N + 1)]
lntable = [0] * (N + 1)
for i in range(1, N + 1):
  for j in range(1, N + 1):
    if d[i][j] > K:
      table[i][j] = 1
      lntable[i] += 1
while True:
  t = 0
  for i in range(1, N + 1):
    if i in vis: continue
    if lntable[i] > lntable[t]: t = i
  if t == 0: break
  for i in range(1, N + 1):
    if table[i][t] == 1:
      table[i][t] = 0
      lntable[i] -= 1
  vis.add(t)
print(len(vis))