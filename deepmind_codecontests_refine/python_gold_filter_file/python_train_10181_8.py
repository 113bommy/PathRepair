#!/usr/bin/env python3
n = int(input())
p = sorted(list(map(int, input().split())) for _ in range(n))

lmax = n - 1
rmin = 0
for i in range(n):
    if p[i][1] <= p[rmin][1]:
        rmin = i

ans = 0

# same(lmax, rmin)
dmax = 0
for i in range(n):
    if i == lmax or i == rmin:
        continue
    if p[i][1] - p[i][0] > p[dmax][1] - p[dmax][0]:
        dmax = i
d1 = max(0, p[rmin][1] - p[lmax][0] + 1)
d2 = max(0, p[dmax][1] - p[dmax][0] + 1)
ans = max(ans, d1 + d2)

# !same(lmax, rmin)
m = lmax
for i in range(rmin, lmax)[::-1]:
    if p[i + 1][1] < p[m][1]:
        m = i + 1
    d1 = max(0, p[rmin][1] - p[i][0] + 1)
    d2 = max(0, p[m][1] - p[lmax][0] + 1)
    ans = max(ans, d1 + d2)

print(ans)
