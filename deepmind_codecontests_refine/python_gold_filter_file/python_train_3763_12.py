import math
import collections

n= int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
z = list(zip(a,b))
zz = []
doublezeros = 0
for idx, t in enumerate(z):
    if t[0] == 0 and t[1] != 0:
        continue
    if t[0] == 0 and t[1] == 0:
        doublezeros += 1
        continue
    if t[0] != 0 and t[1] == 0:
        zz.append((1,0))
        continue
    gcd = math.gcd(t[0], t[1])
    f = 1 if t[0] > 0 else -1
    zz.append((t[0] // gcd * f,    t[1] // gcd*f))
d = collections.defaultdict(int)
for t in zz:
    d[t] += 1
r = max(d.values()) if len(d) > 0 else 0
print(r+doublezeros)
