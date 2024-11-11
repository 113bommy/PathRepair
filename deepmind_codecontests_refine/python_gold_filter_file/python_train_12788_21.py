a, b, c, d, e, f = map(int, input().split())
res = (100 * a, 0)
for aa in range(0, f + 1, 100 * a):
    for bb in range(0, f + 1, 100 * b):
        w = aa + bb
        if w == 0 or w >= f:
            continue
        r = f - w
        for cc in range(0, r + 1, c):
            for dd in range(0, r + 1, d):
                s = cc + dd
                t = w + s
                if t > f or 100 * s > e * w:
                    continue
                if s * res[0] > res[1] * t:
                    res = (t, s)
print(*res)