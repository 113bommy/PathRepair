from collections import defaultdict
from functools import reduce
from operator import mul

MOD = 10 ** 9 + 7

def nCr(n, r):
    r = min(r, n - r)
    if r == 0:
        return 1
    return reduce(mul, range(n, n - r, -1)) // reduce(mul, range(1, r + 1))

N, M = map(int, input().split())

factors = defaultdict(int)
i = 2
while M > 1 and i * i <= M:
    while M % i == 0:
        M //= i
        factors[i] += 1
    i += 1 if i == 2 else 2
if M > 1:
    factors[M] += 1

ans = 1
for n in factors.values():
    ans *= nCr(N + n - 1, n)
    ans %= MOD
print(ans)
