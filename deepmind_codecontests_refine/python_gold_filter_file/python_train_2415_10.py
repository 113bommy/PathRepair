
from math import ceil
from cmath import sqrt


def inp():
    return int(input())


def minput():
    return map(int, input().split())


def linput():
    return list(minput())


n = inp()
m = n
sn = ceil(sqrt(n).real)
if n % 2 == 0:
    m = 2
for i in range(3, sn + 1, 2):
    if n % i == 0:
        if m == 2:
            print(1)
            exit()
        z = i
        while z < n:
            z *= i
        if z == n:
            print(i)
        else:
            print(1)
        exit()
if m == 2:
    print(2 if (n // 2) % 2 != 1 or n == 2 else 1)
else:
    print(m)
