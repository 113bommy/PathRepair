from random import random, randint, randrange
from time import time
import random
import collections
import bisect
import os
import math
from collections import defaultdict, OrderedDict, Counter
from sys import stdin, stdout
from bisect import bisect_left, bisect_right
from queue import Queue, PriorityQueue
from heapq import heapify, heappop, heappush
from statistics import median, mean
from math import gcd, sqrt, floor, factorial, ceil, log2, log10, log
import fractions
import copy
from copy import deepcopy
import sys
import io
sys.setrecursionlimit(10**8)
mod = pow(10, 9)+7


def ncr(n, r, p=mod):
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den,
                      p - 2, p)) % p


def normalncr(n, r):
    r = min(r, n-r)
    count = 1
    for i in range(n-r, n+1):
        count *= i

    for i in range(1, r+1):
        count //= i
    return count


inf = float("inf")
adj = defaultdict(set)
visited = defaultdict(int)


def addedge(a, b):
    adj[a].add(b)
    adj[b].add(a)


def bfs(v):
    q = Queue()
    q.put(v)
    visited[v] = 1
    while q.qsize() > 0:
        s = q.get_nowait()
        print(s)
        for i in adj[s]:
            if visited[i] == 0:
                q.put(i)
                visited[i] = 1


def dfs(v, visited):
    if visited[v] == 1:
        return
    visited[v] = 1

    print(v)
    for i in adj[v]:
        dfs(i, visited)


def reverse_bisect_right(a, x, lo=0, hi=None):
    if lo < 0:
        raise ValueError('lo must be non-negative')
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo+hi)//2
        if x > a[mid]:
            hi = mid
        else:
            lo = mid+1
    return lo


def reverse_bisect_left(a, x, lo=0, hi=None):
    if lo < 0:
        raise ValueError('lo must be non-negative')
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo+hi)//2
        if x >= a[mid]:
            hi = mid
        else:
            lo = mid+1
    return lo


def get_list():
    return list(map(int, input().split()))


def get_str_list_in_int():
    return [int(i) for i in list(input())]


def get_str_list():
    return list(input())


def get_map():
    return map(int, input().split())


def input_int():
    return int(input())


def matrix(a, b):
    return [[0 for i in range(b)] for j in range(a)]


def swap(a, b):
    return b, a


def find_gcd(l):
    a = l[0]
    for i in range(len(l)):
        a = gcd(a, l[i])
    return a


def is_prime(n):
    sqrta = int(sqrt(n))
    for i in range(2, sqrta+1):
        if n % i == 0:
            return 0
    return 1


def prime_factors(n):
    sqrta = int(sqrt(n))
    for i in range(2, sqrta+1):
        if n % i == 0:
            return [i]+prime_factors(n//i)
    return [n]


def p(a):
    if type(a) == str:
        print(a+"\n")
    else:
        print(str(a)+"\n")


def ps(a):
    if type(a) == str:
        print(a)
    else:
        print(str(a))


def kth_no_not_div_by_n(n, k):
    return k+(k-1)//(n-1)


nc = "NO"
yc = "YES"
ns = "No"
ys = "Yes"

t = int(input())
for i in range(t):
    n, m = get_map()
    a = get_list()
    x = get_list()
    suma = sum(a)
    prefix = [0 for _ in range(n)]
    maxa = [0 for _ in range(n)]
    for i in range(n):
        prefix[i] = a[i]
        maxa[i] = prefix[i]
        if i:
            prefix[i] += prefix[i-1]
            maxa[i] = max(prefix[i], maxa[i-1])
    # print(maxa)
    if suma <= 0:
        for i in x:
            indexa = bisect_left(maxa, i)
            if indexa == n:
                print(-1, end=" ")
            else:
                print(indexa, end=" ")
    else:
        for i in x:
            count = 0
            if i <= maxa[-1]:
                indexa = bisect_left(maxa, i) + 1
            else:
                count = ceil((i - maxa[-1])/suma)
                i = i - suma * count
                indexa = 0
                if i != 0:
                    indexa = bisect_left(maxa, i) + 1
            print(count * n + indexa - 1, end=" ")
    print('')

# 1
# 2 2
# 2 -1
# 2 1

# 2 2
# 2 0
# 1 2
# 0 1
