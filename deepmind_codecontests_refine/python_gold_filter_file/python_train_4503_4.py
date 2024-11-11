a, b, c, d = map(int, input().split())
ans = 0
for x in range(a, b + 1):
    min_, max_ = max(b, c - x + 1), min(c, d - x + 1)
    ta, tb = min_ + x - c, max_ + x - c
    ans += (ta + tb) * max(tb - ta + 1, 0) // 2 + \
        (d - c + 1) * min(c - max_, c - b + 1)
print(ans)
