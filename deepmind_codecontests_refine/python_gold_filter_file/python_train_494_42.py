from math import gcd
from collections import defaultdict

MOD = 10 ** 9 + 7

n = int(input())
d = defaultdict(int)
tmp = 0
for i in range(n):
    a, b = map(int, input().split())
    if a == b == 0:
        tmp += 1
    else:
        if b < 0 or (b == 0 and a <= 0):
            a = -a
            b = -b
        g = gcd(a, b)
        a = a // g
        b = b // g
        d[(a, b)] += 1
        if a <= 0:
            d[(b, -a)]
        else:
            d[(-b, a)]
ans = 1
for k, v in d.items():
    a, b = k
    if a <= 0:
        continue
    c = d[(-b, a)]
    ans *= pow(2, v) + pow(2, c) - 1
    ans %= MOD
print((ans + tmp - 1) % MOD)
