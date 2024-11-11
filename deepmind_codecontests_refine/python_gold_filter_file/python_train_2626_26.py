import os
from io import BytesIO

# input = BytesIO(os.read(0, os.fstat(0).st_size)).readline


def check(x, p):
    i = mid - 1
    while i > -1 and a[i] <= p:
        p -= a[i]
        if i >= k - 1:
            i -= k
        else:
            i -= 1
    return i <= -1


for _ in range(int(input())):
    n, p, k = map(int, input().split())
    a = sorted(map(int, input().split()))
    L = 0
    R = n + 1
    while R - L > 1:
        mid = (L + R) >> 1
        if check(mid, p):
            L = mid
        else:
            R = mid
    print(L)
