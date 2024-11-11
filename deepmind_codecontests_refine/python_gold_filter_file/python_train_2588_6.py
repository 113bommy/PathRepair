h, w, n = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(n)]

sa = {}
for a,b in ab:
    for i in range(3):
        aa = a + i
        if aa < 3 or h < aa:
            continue
        for j in range(3):
            bb = b + j
            if bb < 3 or w < bb:
                continue
            id = "%d,%d" % (aa, bb)
            sa[id] = sa.get(id, 0) + 1

s = {}
for x in sa.values():
    s[x] = s.setdefault(x, 0) + 1
print((w - 2) * (h - 2) - len(sa.keys()))
for i in range(1, 10):
    print(s.get(i, 0))