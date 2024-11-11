from functools import reduce
from math import gcd
n = int(input())
def dlog(n, p):
    cnt = 0
    while n % p == 0:
        cnt += 1
        n //= p
    return cnt
l = [*map(int, input().split())]
g = reduce(gcd, l)
aux = sorted((-dlog(l[i] // g, 3), dlog(l[i] // g, 2), i) for i in range(n))
print(*[l[i] for _, __, i in aux])