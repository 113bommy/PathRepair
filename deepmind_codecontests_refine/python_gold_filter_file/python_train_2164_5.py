N,M,S = map(int,input().split())
edges = [[] for _ in range(2500*50 + 100)]
def indexer(city,coin):
    return 50*coin + city

for _ in range(M):
    u,v,a,b = map(int,input().split())
    u -= 1
    v -= 1
    for scoin in range(a,2501):
        edges[indexer(u,scoin)].append((b,indexer(v,scoin-a)))
        edges[indexer(v,scoin)].append((b,indexer(u,scoin-a)))
## 両替
for i in range(N):
    c,d = map(int,input().split())
    for scoin in range(c,2501):
        edges[indexer(i,scoin-c)].append((d,indexer(i,scoin)))


def dijkstra(s,n,edges):
    import heapq
    dist = [float('inf')] * n
    fixed = [False]*n
    dist[s] = 0
    fixed[s] = True
    priority_que = []
    for e in edges[s]:
        heapq.heappush(priority_que,e)

    while len(priority_que):
        edge = heapq.heappop(priority_que)
        if fixed[edge[1]]:
            continue
        v = edge[1]
        dist[v] = edge[0]
        fixed[v] = True
        for ne in edges[v]:
            heapq.heappush(priority_que,(ne[0]+dist[v], ne[1]))
    return dist

d=dijkstra(indexer(0,min(2500,S)),2500*50 + 100,edges)
for i in range(1,N):
    ans = float('inf')
    for j in range(2501):
        ans = min(ans,d[indexer(i,j)])
    print(ans)