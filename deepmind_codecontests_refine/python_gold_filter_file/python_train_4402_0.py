# Not my code
# https://codeforces.com/contest/1416/submission/94027802
import sys,io,os
from collections import defaultdict 
 
inp = [int(x) for x in sys.stdin.buffer.read().split()]
 
n = inp.pop(0)
A = inp
 
t = 0.0
x = 0
for v in range(1, 31)[::-1]:
    u = d = 0.0
    r = defaultdict(int)
    w = 1 << v - 1
    for a in A:
        p = a >> v
        b = a & w
        if b:
            r[p] += 1
        elif p in r:
            d += 2 * r[p]
        r[~p] += 1
    for p in r:
        if p >= 0 and ~p in r:
            rp = r[p] + 0.0
            cp = r[~p] + 0.0
            u += cp * (cp - 1) - rp * (rp - 1) - (cp - rp) * (cp - rp - 1)
    if d > u - d:
        x += w
        d = u - d
    t += d
print(int(t) // 2, x)