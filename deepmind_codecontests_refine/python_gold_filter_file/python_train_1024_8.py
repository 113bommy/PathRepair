N, M = map(int, input().split())

MAX = 10**10
dist = [[0 if x == i else MAX for x in range(N)] for i in range(N)]
edge_list = []
for i in range(M):
    a, b, c = map(int, input().split())
    edge = [a, b, c]
    edge_list.append(edge)
    dist[a-1][b-1] = c
    dist[b-1][a-1] = c

#Warshall-Floyd
for k in range(N):
    for i in range(N):
        for j in range(N):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

ans = 0
for edge in edge_list:
    a, b, c = edge
    if dist[a-1][b-1] < c:
        ans += 1
print(ans)