
from heapq import heappop, heappush

N, M, S = map(int, input().split())
X = [list(map(int, input().split())) for _ in range(M)]
Y = [list(map(int, input().split())) for _ in range(N)]

lim = 2501
graph = [[] for _ in range((N + 1) * lim)]

for u, v, a, b in X:
    for n in range(a, lim):
        graph[u * lim + n].append((v * lim + (n - a), b))
        graph[v * lim + n].append((u * lim + (n - a), b))

for n, (c, d) in enumerate(Y):
    for x in range(lim - 1):
        graph[(n + 1) * lim + x].append(
            ((n + 1) * lim + min(lim - 1, x + c), d))


INF = 10 ** 20
start = lim + min(S, lim - 1)
dist = [INF] * ((N + 1) * lim + 1)
dist[start] = 0
pq = []
heappush(pq, (0, start))

while pq:
    _, u = heappop(pq)
    for v, c in graph[u]:
        if dist[v] > dist[u] + c:
            dist[v] = dist[u] + c
            heappush(pq, (dist[v], v))

ans = []
for i in range(2, N + 1):
    ans.append(min(dist[i * lim:i * lim + lim]))

print(*ans, sep="\n")
