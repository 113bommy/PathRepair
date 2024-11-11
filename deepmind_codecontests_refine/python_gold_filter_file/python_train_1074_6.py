from sys import stdin,stdout
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
mod = 1000000007
from math import pi
n = ii1()
arr = sorted([0] + iia())
res = 0
if n < 2:
    res = (arr[1])**2
else:
    for i in range(n,0,-2):
        if i > 0:
            # print(i,i-1)
            res += arr[i] ** 2 - arr[i - 1] ** 2
print(pi*res)
