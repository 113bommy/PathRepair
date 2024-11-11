import sys
input = sys.stdin.readline

INF = 10**18
mod = 10**9+7
# AOJ GRL_1_A Single Sourse Shortest Path
import heapq as hp

N, M = map(int, input().split())
s, t = map(int, input().split())
s -= 1; t -= 1
graph = [[] for _ in range(N)]
for _ in range(M):
    n, m, d = map(int, input().split())
    graph[n-1].append((d, m-1)) 
    graph[m-1].append((d, n-1)) #無向グラフならこれ使う

def dijkstra(s):
    D = [INF for _ in range(N)] # 頂点iへの最短距離がD[i]
    B = [0]*N
    D[s] = 0
    B[s] = 1
    q = [] # しまっていく優先度付きキュー
    hp.heappush(q, (0, s))

    while q:
        nd, np = hp.heappop(q)
        if D[np] < nd:
            continue
        for d, p in graph[np]:
            if D[p] > D[np] + d:
                D[p] = D[np] + d
                B[p] = B[np]
                hp.heappush(q, (D[p], p))
            elif D[p] == D[np] + d:
                B[p] = (B[p] + B[np])%mod
    return D, B

sD, sB = dijkstra(s)
tD, tB = dijkstra(t)

distance = sD[t]

ans = 0
for n in range(N):
    for d, m in graph[n]:
        if sD[n] + d + tD[m] == distance and 2*sD[n] < distance < 2*(sD[n]+d):
            ans = (ans + (sB[n]*tB[m])**2)%mod
    if sD[n] + tD[n] == distance and 2*sD[n] == distance:
        ans = (ans + (sB[n]*tB[n])**2) % mod
ans = (sB[t]*tB[s] - ans) % mod
print(ans)