import math
import itertools


def ria():
    return [int(i) for i in input().split()]


def sum_range(start, end):
    return int((end * (end + 1) // 2) - (start - 1) * start // 2)


n, m = ria()


def f(k):
    global n, m
    return n - sum_range(m+1, m + k) + m * (k-1) <= 0


if n <= m:
    print(n)
    exit(0)

l, r = 1, n + m

while l < r:
    m1 = (l + r) // 2
    if not f(m1):
        l = m1 + 1
    elif f(m1 - 1):
        r = m1 - 1
    else:
        l, r = m1, m1
        break

res = r
if f(l):
    res = l
print(res + m)

suma = m
