n, m = map(int, input().split())

import math
res = []
mx = n if m >= 2 * n - 1 else math.ceil(m / 2)

for i in range(mx):
    k = 2 * i + 1
    l = 2 * n + k
    if l <= m:
        res.append(l)
    res.append(k)
    if l + 1 <= m:
        res.append(l + 1)
    if k + 1 <= m:
        res.append(k + 1)

print(*res)
    
