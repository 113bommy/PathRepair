import itertools
N, M, R = map(int, input().split())
INF = 2 ** 63 - 1
d = [[INF for i in range(N+1)] for j in range(N+1)]
r = list(map(int, input().split()))
r = list(itertools.permutations(r))
for i in range(M):
    a, b, c = map(int, input().split())
    d[a][b] = c
    d[b][a] = c
for i in range(N+1):
    d[i][i] = 0


for k in range(N+1):
    for i in range(N+1):
        for j in range(N+1):
            d[i][j] = min(d[i][j], d[i][k] + d[k][j])

ans = INF
for path in r:
    anstemp = 0
    for i in range(R-1):
        anstemp += d[path[i]][path[i+1]]
    ans = min(anstemp, ans)
print(ans)
