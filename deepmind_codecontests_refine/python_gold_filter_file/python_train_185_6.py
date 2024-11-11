# -*- coding: utf-8 -*-
from collections import Counter
N, P = map(int, input().split())


def primes(n):
    primfac = []
    d = 2
    while d*d <= n:
        while (n % d) == 0:
            primfac.append(d)  # supposing you want multiple factors repeated
            n //= d
        d += 1
    if n > 1:
       primfac.append(n)
    return primfac

ctr = Counter(primes(P))

ans = 1
for k,v in ctr.items():
    if v >= N:
        ans *= k ** (v//N)

print(ans)
