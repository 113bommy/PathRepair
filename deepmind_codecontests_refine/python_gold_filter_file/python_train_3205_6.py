n, m = map(int, input().split())
h = [None] + [int(x) for x in input().split()]

res = [0] + ([1] * n)

for _ in range(m):
    a, b = map(int, input().split())
    if h[a] >= h[b]:
        res[b] = 0
    if h[a] <= h[b]:
        res[a] = 0

print(sum(res))
