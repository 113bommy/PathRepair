import itertools
N, M, R = map(int, input().split())
r = list(map(int, input().split()))
r = list(map(lambda x: x - 1, r))
d = [[10 ** 10] * N for _ in range(N)]

for _ in range(M):
    a, b, c = map(int, input().split())
    d[a - 1][b - 1] = c
    d[b - 1][a - 1] = c

for i in range(N):
    d[i][i] = 0

for k in range(N):
    for i in range(N):
        for j in range(N):
            d[i][j] = min(d[i][j], d[i][k] + d[k][j])

ans = 10 ** 10

for i in itertools.permutations(r):
    dist = 0
    for j in range(R - 1):
        dist += d[i[j]][i[j + 1]]
    ans = min(ans, dist)

print(ans)
