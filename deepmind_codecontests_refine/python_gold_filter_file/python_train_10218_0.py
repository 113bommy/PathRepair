#!/usr/bin/env python3
import os
import sys
from functools import reduce
from io import BytesIO, IOBase

sys.stdout, stream = IOBase(), BytesIO()
sys.stdout.flush = lambda: os.write(1, stream.getvalue()) and not stream.truncate(0) and stream.seek(0)
sys.stdout.write = lambda s: stream.write(s.encode())

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline


def gcd(x, y):
    """ greatest common divisor of x and y """
    while y:
        x, y = y, x % y
    return x


lcm = lambda a, b: a * b // gcd(a, b)


def main():
    n, k = map(int, input().split())
    a, b = map(int, input().split())

    ans = [10**12, 0]

    ls = {(a + b) % k, (a - b) % k, (-a + b) % k, (-a - b) % k}
    for li in ls:
        while li < n * k:
            res = n * k // gcd(n * k, li if li else n * k)
            ans = [min(ans[0], res), max(ans[1], res)]
            li += k

    print(*ans)


if __name__ == '__main__':
    main()
