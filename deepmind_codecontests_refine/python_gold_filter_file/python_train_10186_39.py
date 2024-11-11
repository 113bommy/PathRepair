from itertools import permutations
n, m, r = map(int, input().split())
R = list(map(lambda x: int(x)-1, input().split()))
INF = 10**18
dist = [[INF]*n for _ in range(n)]
for _ in range(m):
    a, b, c = map(int, input().split())
    dist[a-1][b-1] = c
    dist[b-1][a-1] = c

for k in range(n):
    for i in range(n):
        for j in range(n):
            dist[i][j] = min(dist[i][k]+dist[k][j], dist[i][j])

ans = INF
for subset in permutations(R):
    d = 0
    for v, v2 in zip(subset, subset[1:]):
        d += dist[v][v2]
    if d < ans:
        ans = d
print(ans)
