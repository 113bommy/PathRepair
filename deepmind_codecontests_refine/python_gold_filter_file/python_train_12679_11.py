inf = 10 ** 13

n, m, l = map(int, input().split())

d = [[inf] * n for _ in range(n)]
for _ in range(m):
    a, b, c = map(int, input().split())
    d[a - 1][b - 1] = d[b - 1][a - 1] = c
for k in range(n):
    for i in range(n):
        for j in range(n):
            d[i][j] = min(d[i][j], d[i][k] + d[k][j])

e = [[1 if d[i][j] <= l else inf for j in range(n)] for i in range(n)]
for k in range(n):
    for i in range(n):
        for j in range(n):
            e[i][j] = min(e[i][j], e[i][k] + e[k][j])

q = int(input())
for _ in range(q):
    s, t = map(int, input().split())
    a = e[s - 1][t - 1]
    print(a - 1 if a < inf else -1)
