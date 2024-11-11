from sys import stdin,stdout
from math import gcd, ceil, sqrt
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
mod = 1000000007

n = ii1()
res = 0
if n >=2:
    res = n*(6 + (6*n))//2
elif n>=1:
    res = 6
print(res+1)
    