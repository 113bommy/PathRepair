# -*- coding: utf-8 -*-
from heapq import heappop, heappush
def inpl(): return map(int, input().split())
N = int(input())

X = []
Y = []

for i in range(N):
    x, y = inpl()
    X.append((i, x))
    Y.append((i, y))

X = sorted(X, key=lambda x: x[1])
Y = sorted(Y, key=lambda y: y[1])

G = [[] for _ in range(N)]
for i in range(N-1):
    Xa, Xb = X[i], X[i+1]
    Ya, Yb = Y[i], Y[i+1]
    G[Xa[0]].append([Xb[0], Xb[1]-Xa[1]])
    G[Xb[0]].append([Xa[0], Xb[1]-Xa[1]])
    
    G[Ya[0]].append([Yb[0], Yb[1]-Ya[1]])
    G[Yb[0]].append([Ya[0], Yb[1]-Ya[1]])

visited = [False]*N
Q = [(0, 0)]
ans = 0

while Q:
    c, n = heappop(Q)
    if visited[n]:
        continue
    visited[n] = True
    ans += c
    
    for m, d in G[n]:
        if visited[m]:
            continue
        else:
            heappush(Q, (d, m))

print(ans)