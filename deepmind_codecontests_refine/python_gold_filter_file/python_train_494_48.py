from collections import defaultdict
from math import gcd

n = int(input())

zeros = 0
d = defaultdict(lambda: [0, 0])
for _ in range(n):
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        zeros += 1
        continue
    g = gcd(a, b)
    a, b = a // g, b // g
    if a == 0:
        b = 1
    if b == 0:
        a = 1
    if b < 0:
        a, b = -a, -b
    if a <= 0:
        d[(b, -a)][1] += 1
    else:
        d[(a, b)][0] += 1


mod = 1000000007
ans = 1
for v in d.values():
    ans = ans * (pow(2, v[0], mod) + pow(2, v[1], mod) - 1) % mod

ans = (ans - 1 + zeros) % mod
print(ans)
