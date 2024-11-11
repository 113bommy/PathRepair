t = int(input())
from math import gcd
res = []

for _ in range(t):
    x, y = map(int, input().split())
    n = 0
    if x <= y:
        n = y - (y%x)//2
    else: n = x + y
    res.append(n)

for el in res: print(el)