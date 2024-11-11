from sys import stdin,stdout
from math import gcd, ceil, sqrt
from collections import Counter
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
mod = 1000000007

tc = ii1()
for _ in range(tc):
    n = ii1()
    e = iia()
    d = Counter(e)
    extra = 0
    group = 0
    for i in sorted(d):
        group += (d[i] + extra) // i
        extra = (d[i] + extra) % i
    print(group)            