# Author: S Mahesh Raju
# Username: maheshraju2020
# Date: 21/08/2020

from sys import stdin, stdout, setrecursionlimit
from math import gcd, ceil, sqrt
from collections import Counter, deque
from bisect import bisect_left, bisect_right
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
setrecursionlimit(100000)
mod = 1000000007

tc = ii1()
for _ in range(tc):
    n, k = iia()
    if n == k:
        print(0)
    elif k > n:
        print(k - n)
    else:
        if (n + k) % 2 == 0:
            print(0)
        else:
            print(1)
            
            
    