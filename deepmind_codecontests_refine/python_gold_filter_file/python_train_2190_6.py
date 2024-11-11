# -*- coding: utf-8 -*-
def inpl(): return tuple(map(int, input().split()))
 
INF = float("inf")
 
V, E = inpl()
adj = [[] for _ in range(V)]
D = [[INF]*V for _ in range(V)]
 
for _ in range(E):
    s, t, d = inpl()
    D[s][t] = d
 
for v in range(V):
    D[v][v] = 0 

def WarshallFloyd(G):
    V = len(G)
    for k in range(V):
        for i in range(V):
            for j in range(V):
                G[i][j] = min(G[i][j], G[i][k] + G[k][j])
    return G

D = WarshallFloyd(D)

for v in range(V):
    if D[v][v] < 0:
        print("NEGATIVE CYCLE")
        break
else:
    for d in range(V):
        print(" ".join(map(str, D[d])).replace("inf", "INF"))
