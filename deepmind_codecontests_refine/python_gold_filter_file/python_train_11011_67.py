#!/usr/bin/env python3
from itertools import*
n, k, *A = map(int, open(0).read().split())

def imos(l, r):
    B[l] += 1
    if r + 1 != n:
        B[r + 1] -= 1

for _ in [0] * min(k, 41):
    B = [0] * n
    for i, a in enumerate(A):
        imos(max(i - a, 0), min(i + a, n - 1))
    *A, = accumulate(B)
print(*A)