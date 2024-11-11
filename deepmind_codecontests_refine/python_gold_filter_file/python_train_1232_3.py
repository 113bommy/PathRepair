# -*- coding: utf-8 -*-
from collections import deque
def inpl(): return map(int, input().split())
N = int(input())

G = [[] for _ in range(N+1)]
for _ in range(N-1):
    a, b, c = inpl()
    G[a].append((b, c))
    G[b].append((a, c))

D = [0] * (N+1)
Q, K = inpl()
DQ = deque([K])
visited = [False]*(N+1)

while DQ:
    p = DQ.popleft()
    visited[p] = True
    for q, c in G[p]:
        if not visited[q]:
            D[q] = D[p] + c
            DQ.append(q)

for _ in range(Q):
    x, y = inpl()
    print(D[x] + D[y])