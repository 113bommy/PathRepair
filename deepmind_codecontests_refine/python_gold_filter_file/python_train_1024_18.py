n, m = map(int, input().split())
INF = float('inf')
graph = [[INF for i in range(n)] for j in range(n)]
tmp = []

for i in range(m):
    a, b, c = map(int, input().split())
    graph[a - 1][b - 1] = c
    graph[b - 1][a - 1] = c
    tmp.append((a - 1, b - 1, c))

for k in range(n):
    for i in range(n):
        for j in range(n):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

ans = 0
for a, b, c in tmp:
    if c > graph[a][b]:
        ans += 1

print(ans)
