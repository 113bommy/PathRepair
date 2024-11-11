# Author: S Mahesh Raju
# Username: maheshraju2020
# Date: 29/04/2020

from sys import stdin,stdout
from math import gcd, ceil, sqrt
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
mod = 1000000007

n = ii1()
x, res = 1, 0
while int(bin(x)[2:]) <= n:
    x += 1
    res += 1
print(res)