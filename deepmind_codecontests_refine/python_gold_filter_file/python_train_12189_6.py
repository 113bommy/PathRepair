import heapq


def main():
    nvertices, nedges, s = map(int, input().split())
    adj = [[] for i in range(nvertices)]
    for i in range(nedges):
        u, v, w = map(int, input().split())
        adj[u].append((v, w))

    INF = float('inf')
    costs = [INF] * nvertices
    costs[s] = 0
    que = [(0, s)]
    for i in range(1, nvertices):
        que.append((INF, 1))
    while que:
        cost, u = heapq.heappop(que)
        if cost > costs[u]:
            continue
        costs[u] = cost
        for v, w in adj[u]:
            if costs[v] > costs[u] + w:
                costs[v] = costs[u] + w
                heapq.heappush(que, (costs[v], v))

    for i in range(nvertices):
        print(costs[i] if costs[i] < INF else "INF")


main()