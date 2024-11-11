'''
      ___           ___                         ___                       ___           ___                         ___
     /\__\         /\  \         _____         /\  \                     /\  \         /\  \                       /\__\
    /:/ _/_        \:\  \       /::\  \        \:\  \       ___         /::\  \       |::\  \         ___         /:/ _/_
   /:/ /\  \        \:\  \     /:/\:\  \        \:\  \     /\__\       /:/\:\__\      |:|:\  \       /\__\       /:/ /\  \
  /:/ /::\  \   ___  \:\  \   /:/  \:\__\   ___ /::\  \   /:/__/      /:/ /:/  /    __|:|\:\  \     /:/  /      /:/ /::\  \
 /:/_/:/\:\__\ /\  \  \:\__\ /:/__/ \:|__| /\  /:/\:\__\ /::\  \     /:/_/:/__/___ /::::|_\:\__\   /:/__/      /:/_/:/\:\__\
 \:\/:/ /:/  / \:\  \ /:/  / \:\  \ /:/  / \:\/:/  \/__/ \/\:\  \__  \:\/:::::/  / \:\~~\  \/__/  /::\  \      \:\/:/ /:/  /
  \::/ /:/  /   \:\  /:/  /   \:\  /:/  /   \::/__/       ~~\:\/\__\  \::/~~/~~~~   \:\  \       /:/\:\  \      \::/ /:/  /
   \/_/:/  /     \:\/:/  /     \:\/:/  /     \:\  \          \::/  /   \:\~~\        \:\  \      \/__\:\  \      \/_/:/  /
     /:/  /       \::/  /       \::/  /       \:\__\         /:/  /     \:\__\        \:\__\          \:\__\       /:/  /
     \/__/         \/__/         \/__/         \/__/         \/__/       \/__/         \/__/           \/__/       \/__/

'''
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
from math import gcd, inf, sqrt, pi, cos, sin, ceil, log2, floor, log
from bisect import bisect_right, bisect_left, bisect

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

from functools import reduce
from sys import stdin, stdout, setrecursionlimit
setrecursionlimit(2**20)


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
    return (list(factors))


def isPowerOfTwo(x):
    return (x and (not(x & (x - 1))))

MOD = 1000000007
PMOD = 998244353
N = 10**6
LOGN = 30
alp = 'abcdefghijklmnopqrstuvwxyz'
T = 1
# T = int(stdin.readline())
for _ in range(T):
    # n, k = list(map(int, stdin.readline().rstrip().split()))
    # n = int(stdin.readline())
    # a = list(map(int, stdin.readline().rstrip().split()))
    # b = list(map(int, stdin.readline().rstrip().split()))
    s = list(stdin.readline().strip('\n'))
    # b = list(stdin.readline().strip('\n'))
    # m = int(stdin.readline())
    # c = list(map(int, stdin.readline().rstrip().split()))
    st = []
    for i in s:
        if len(st) < 2:
            st.append(i)
        else:
            if len(st) >= 3:
                if (st[-3] == st[-2]) and (st[-1] == i):
                    continue
            if st[-1] == i and st[-2] == i:
                continue
            else:
                st.append(i)
    for i in st:
        print(i, end='')
    print()
