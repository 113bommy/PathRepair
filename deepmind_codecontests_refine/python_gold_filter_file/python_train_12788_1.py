A, B, C, D, E, F = map(int, input().split())
conc = -1
ans = (0, 0)
for a in range(0, F + 1, 100 * A):
    for b in range(0, F - a + 1, 100 * B):
        w = a + b
        if w == 0:
            continue
        for c in range(0, min(w * E // 100, F - w) + 1, C):
            d = min(w * E // 100 - c, F - w - c) // D * D
            s = c + d
            if conc < s / (w + s):
                conc = s / (w + s)
                ans = (w + s, s)
print(*ans)
