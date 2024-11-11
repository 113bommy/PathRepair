# -*- coding: utf-8 -*-

n = int(input())
a = [int(x) for x in input().split()]

ans = 1e16
for s in (1, -1):
    res, cumsum = 0, 0
    for j in range(n):
        cumsum += a[j]
        if cumsum * s <= 0:
            res += abs(cumsum-s)
            cumsum = s
        s *= -1
    ans = min(ans, res)

print(ans)