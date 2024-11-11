n, m, r = map(int, input().split())
v = list(map(int, input().split()))

inf = 10 ** 18
d = [[inf for _ in range(n)] for _ in range(n)]
for i in range(n):
    d[i][i] = 0
for _ in range(m):
    a, b, c = map(int, input().split())
    d[a-1][b-1] = c
    d[b-1][a-1] = c

for k in range(n):
    for i in range(n):
        for j in range(n):
            d[i][j] = min(d[i][j], d[i][k] + d[k][j])

import itertools
ans = 10 ** 18
for a in itertools.permutations(v):
    dis = 0
    for i in range(r-1):
        dis += d[a[i+1]-1][a[i]-1]
    ans = min(ans, dis)
print(ans)