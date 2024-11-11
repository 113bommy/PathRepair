N, M = map(int, input().split())
a = list(map(int, input().split()))

from math import floor
from fractions import gcd
from functools import reduce


def lcm(x, y):
    return x * y // gcd(x, y)


b = [n // 2 for n in a]

lcm_b = reduce(lcm, b)

for n in b:
    if (lcm_b // n) % 2 == 0:
        print(0)
        exit()

n = floor((M / lcm_b - 1) / 2) + 1

print(n)
