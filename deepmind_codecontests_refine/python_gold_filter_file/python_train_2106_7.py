import sys
import os
import time
import collections
from collections import Counter, deque
import itertools
import math
import timeit
import random

#########################
# imgur.com/Pkt7iIf.png #
#########################

def sieve(n):
    if n < 2: return list()
    prime = [True for _ in range(n + 1)]
    p = 3
    while p * p <= n:
        if prime[p]:
            for i in range(p * 2, n + 1, p):
                prime[i] = False
        p += 2
    r = [2]
    for p in range(3, n + 1, 2):
        if prime[p]:
            r.append(p)
    return r

def divs(n, start=1):
    divisors = []
    for i in range(start, int(math.sqrt(n) + 1)):
        if n % i == 0:
            if n / i == i:
                divisors.append(i)
            else:
                divisors.extend([i, n // i])
    return divisors

def divn(n, primes):
    divs_number = 1
    for i in primes:
        if n == 1:
            return divs_number
        t = 1
        while n % i == 0:
            t += 1
            n //= i
        divs_number *= t

def flin(d, x, default=-1):
    left = right = -1
    for i in range(len(d)):
        if d[i] == x:
            if left == -1: left = i
            right = i
    if left == -1:
        return (default, default)
    else:
        return (left, right)

def ceil(n, k): return n // k + (n % k != 0)
def ii(): return int(input())
def mi(): return map(int, input().split())
def li(): return list(map(int, input().split()))
def lcm(a, b): return abs(a * b) // math.gcd(a, b)
def prr(a, sep=' '): print(sep.join(map(str, a)))
def dd(): return collections.defaultdict(int)
def ddl(): return collections.defaultdict(list)


input = sys.stdin.readline

res = []
for _ in range(ii()):
    n, start = mi()
    b = t = start
    prev = 0
    good = True
    for _ in range(n):
        time, l, h = mi()
        if not good: continue
        k, prev = time - prev, time
        top = min(t + k, h)
        bot = max(b - k, l)
        if top < l or bot > h: good = False
        b, t = bot, top
    print('YES' if good else 'NO')
prr(res, '\n')








