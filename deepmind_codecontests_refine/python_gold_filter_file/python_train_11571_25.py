from math import *

n, v = map(int,input().split())
if n < v:
    print(n - 1)
else:
    print(v + (n - v) * (n - v + 1) // 2 - 1)