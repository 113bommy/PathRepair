import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

n, m = map(int, input().split())
a = sorted((int(ai) for ai in input().split()), reverse=True)

lo, hi = 1, n + 1
while lo < hi:
    mi = (lo + hi) // 2
    if sum(max(0, a[i] - i // mi) for i in range(n)) >= m:
        hi = mi
    else:
        lo = mi + 1

os.write(1, str(lo).encode() if lo <= n else b'-1')
