from sys import stdin,stdout
from math import gcd,ceil
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
mod = 1000000007

n, k = iia()
arr = [0] * (2 * k - n) + iia()
res = 0
l, r = 0, 1
for i in range(len(arr)//2):
    a, b = arr[l], arr[-r]
    res = max(res,a+b)
    l += 1
    r += 1
print(res)