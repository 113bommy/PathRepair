from collections import deque

N,M = map(int, input().split())

graph = [[] for i in range(N)]
for i in range(M):
    L,R,D = map(int, input().split())
    graph[L-1].append([R-1, D])
    graph[R-1].append([L-1, -D])

dist = [int(1e10)] * N

def bfs(id):
    Q = deque()
    Q.append(id)
    dist[id] = 0

    while len(Q) != 0:
        v = Q.popleft()

        for edge in graph[v]:
            u, d = edge[0], edge[1]

            if dist[u] == int(1e10):
                dist[u] = dist[v] + d
                Q.append(u)
            elif dist[u] != dist[v] + d:
                print("No")
                exit()


for i in range(N):
    if dist[i] == int(1e10):
        bfs(i)

print("Yes")


