t = {}
p = [sorted(map(int, input().split())) for i in range(int(input()))]
s, k = 0, []
for i, (x, y, z) in enumerate(p, 1):
    for a, b, c in [(x, y, z), (x, z, y), (y, z, x)]:
        d, j = t.get((a, b), (0, 0))
        if j == i: continue
        r = min(a, d + c)
        if r > s: s, k = r, (2, i, j) if j else (1, i)
        if c > d: t[(a, b)] = (c, i)
for q in k: print(q)