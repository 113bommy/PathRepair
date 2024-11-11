import heapq
N, M, s, t = map(int, input().split())
s, t = s - 1, t - 1
G_yen = [[] for i in range(N)]
G_snuuk = [[] for i in range(N)]
for i in range(M):
    u, v, a, b = map(int, input().split())
    u, v = u - 1, v - 1
    G_yen[u].append([v, a])
    G_yen[v].append([u, a])
    G_snuuk[u].append([v, b])
    G_snuuk[v].append([u, b])


def dijkstra(x, G):
    d = [float('inf')] * N
    d[x] = 0
    visited = {x}

    # d, u
    hq = [(0, x)]

    while hq:
        u = heapq.heappop(hq)[1]
        visited.add(u)

        for node, cost in G[u]:
            if (node not in visited) and d[node] > d[u] + cost:
                d[node] = d[u] + cost
                heapq.heappush(hq, (d[u]+cost, node))
    return d


d_yen = dijkstra(s, G_yen)
d_snuuk = dijkstra(t, G_snuuk)

ans = 10 ** 15
ans_list = []
for i in reversed(range(N)):
    ans = min(ans, d_yen[i] + d_snuuk[i])
    ans_list.append(10 ** 15 - ans)

print(*ans_list[::-1], sep='\n')
