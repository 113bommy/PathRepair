"""
  ____          _      _____
 / ___|___   __| | ___|  ___|__  _ __ ___ ___  ___
| |   / _ \ / _` |/ _ \ |_ / _ \| '__/ __/ _ \/ __|
| |__| (_) | (_| |  __/  _| (_) | | | (_|  __/\__ \
 \____\___/ \__,_|\___|_|  \___/|_|  \___\___||___/

"""
"""
░░██▄░░░░░░░░░░░▄██
░▄▀░█▄░░░░░░░░▄█░░█░
░█░▄░█▄░░░░░░▄█░▄░█░
░█░██████████████▄█░
░█████▀▀████▀▀█████░
▄█▀█▀░░░████░░░▀▀███
██░░▀████▀▀████▀░░██
██░░░░█▀░░░░▀█░░░░██
███▄░░░░░░░░░░░░▄███
░▀███▄░░████░░▄███▀░
░░░▀██▄░▀██▀░▄██▀░░░
░░░░░░▀██████▀░░░░░░
░░░░░░░░░░░░░░░░░░░░
"""

import sys
import math
import collections
import operator as op
from collections import deque
from math import gcd, inf, sqrt
from bisect import bisect_right, bisect_left

#sys.stdin = open('input.txt', 'r')
#sys.stdout = open('output.txt', 'w')

from functools import reduce
from sys import stdin, stdout, setrecursionlimit
setrecursionlimit(2**20)


def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n - 1)


def ncr(n, r):
    r = min(r, n - r)
    numer = reduce(op.mul, range(n, n - r, -1), 1)
    denom = reduce(op.mul, range(1, r + 1), 1)
    return numer // denom  # or / in Python 2


def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return len(set(factors))


def isPowerOfTwo(x):
    return (x and (not(x & (x - 1))))


def factors(n):
    return list(set(reduce(list.__add__, ([i, n // i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))


def printp(p):
    for i in p:
        print(i)

MOD = 10**9 + 7
T = 1
# T = int(stdin.readline())
for _ in range(T):
    # n, k = list(map(int, stdin.readline().split()))
    # s1 = list(stdin.readline().strip('\n'))
    # s = str(stdin.readline().strip('\n'))
    # n = int(stdin.readline())
    # a = list(map(int, stdin.readline().split()))
    n, m, k, t = list(map(int, stdin.readline().split()))
    # s = list(stdin.readline().strip('\n'))
    rc = [0] * (n)
    ix = []
    res = ['Waste', 'Carrots', 'Kiwis', 'Grapes']
    for i in range(k):
        x, y = list(map(int, stdin.readline().split()))
        ix.append(y + (x - 1) * m)
    ix.sort()
    for i in range(t):
        x, y = list(map(int, stdin.readline().split()))
        val = y + (x - 1) * m
        c = 0
        temp = -1
        for i in range(len(ix)):
            if val == ix[i]:
                temp = 1
                break
            elif val > ix[i]:
                c += 1
            else:
                break
        if temp == 1:
            print(res[0])
            continue
        val -= c
        if val % 3 == 0:
            print(res[3])
        elif val % 3 == 1:
            print(res[1])
        else:
            print(res[2])
