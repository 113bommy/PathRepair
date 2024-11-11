from heapq import heappush, heappop
from collections import deque
N, M = map(int, input().split())
S, T = map(int, input().split())
S -= 1; T -= 1
G = [[] for i in range(N)]
for i in range(M):
    u, v, d = map(int, input().split())
    G[u-1].append((v-1, d))
    G[v-1].append((u-1, d))

INF = 10**18
MOD = 10**9 + 7

dist = [INF]*N
dist[S] = 0
que = [(0, S)]
while que:
    cost, v = heappop(que)
    if dist[v] < cost:
        continue
    for w, c in G[v]:
        if cost + c < dist[w]:
            dist[w] = cost + c
            heappush(que, (cost + c, w))

que = deque()
mi = [0]*N
que.append(T)
mi[T] = 1
H = [[] for i in range(N)]
RH = [[] for i in range(N)]

D = dist[T]

V = []
E = []
while que:
    v = que.popleft()
    d = dist[v]
    if d*2 == D:
        V.append(v)
    for w, c in G[v]:
        if d == dist[w] + c:
            if dist[w]*2 < D < d*2:
                E.append((w, v))
            H[v].append(w)
            RH[w].append(v)
            if mi[w] == 0:
                mi[w] = 1
                que.append(w)

def bfs(G, RG, s):
    *deg, = map(len, RG)
    que = deque([s])
    res = [0]*N
    res[s] = 1
    while que:
        v = que.popleft()
        for w in G[v]:
            deg[w] -= 1
            res[w] += res[v]
            if deg[w] == 0:
                que.append(w)
                res[w] %= MOD
    return res
CT = bfs(H, RH, T)
CS = bfs(RH, H, S)

ans = CS[T] * CT[S] % MOD
for v in V:
    ans -= (CS[v] * CT[v]) ** 2
    ans %= MOD
for v, w in E:
    ans -= (CS[v] * CT[w]) ** 2
    ans %= MOD
print(ans)
