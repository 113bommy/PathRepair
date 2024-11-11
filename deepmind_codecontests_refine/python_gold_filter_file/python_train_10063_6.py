from bisect import bisect_left
n, k = map(int, input().split())
r = [int(x) for x in input().split()]
r_sorted = sorted(r.copy())
ans = [0]*n

d = {}
for i in range(n):
    d[i] = []

for _ in range(k):
    x, y = map(int, input().split())
    x -= 1; y -= 1
    if r[x] > r[y]:
        d[x].append(y)
    if r[y] > r[x]:
        d[y].append(x)

for i in range(n):
    res = bisect_left(r_sorted, r[i])
    res -= len(d[i])
    if res > 0: ans[i] += res
print(*ans)
