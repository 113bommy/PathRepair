import copy
N, M = map(int, input().split())
INF = 2 ** 63 - 1
d = [[INF for i in range(N+1)] for j in range(N+1)]
for i in range(N+1):
    d[i][i] = 0

for i in range(M):
    a, b, c = map(int, input().split())
    d[a][b] = c
    d[b][a] = c

d_original = copy.deepcopy(d)

for k in range(1, N+1):
    for j in range(1, N+1):
        for i in range(1, N+1):
            d[i][j] = min(d[i][j], d[i][k] + d[k][j])

ans = 0
for i in range(1, N+1):
    for j in range(i+1, N+1):
        if d_original[i][j] != INF and d[i][j] != d_original[i][j]:
            ans += 1
print(ans)
