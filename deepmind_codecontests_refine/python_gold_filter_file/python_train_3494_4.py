from collections import defaultdict
d = defaultdict(set)
s, k = 0, []
for i in range(int(input())):
    x, y, z = sorted(map(int, input().split()))
    for a, b, c in [(x, y, z), (x, z, y), (y, z, x)]:
        d[(a, b)].add((c, i))
    q = min(x, y, z)
    if q > s: s, k = q, (0, i)
for (a, b), t in d.items():
    if len(t) < 2: continue
    (x, i), (y, j) = sorted(t)[-2:]
    q = min(a, x + y)
    if s < q: s, k = q, (1, i, j)
for i in k: print(i + 1)