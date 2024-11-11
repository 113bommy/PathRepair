import os,io
from sys import stdout
import collections
# import random
# import math
# from operator import itemgetter
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# from collections import Counter
# from decimal import Decimal
# import heapq
# from functools import lru_cache

import sys
# import threading
# sys.setrecursionlimit(10**6)
# threading.stack_size(102400000)

# from functools import lru_cache
# @lru_cache(maxsize=None)

######################
# --- Maths Fns  --- #
######################
def primes(n):
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if sieve[i]]

def binomial_coefficient(n, k):
    if 0 <= k <= n:
        ntok = 1
        ktok = 1
        for t in range(1, min(k, n - k) + 1):
            ntok *= n
            ktok *= t
            n -= 1
        return ntok // ktok
    else:
        return 0

def powerOfK(k, max):
    if k == 1:
        return [1]
    if k == -1:
        return [-1, 1]

    result = []
    n = 1
    while n <= max:
        result.append(n)
        n *= k
    return result

def divisors(n):
    i = 1
    result = []
    while i*i <= n:
        if n%i == 0:
            if n/i == i:
                result.append(i)
            else:
                result.append(i)
                result.append(n/i)
        i+=1
    return result

def distance(xa, ya, xb, yb):
    return ((ya-yb)**2 + (xa-xb)**2)**(0.5)

# @lru_cache(maxsize=None)
def digitsSum(n):
    if n == 0:
        return 0
    r = 0
    while n > 0:
        r += n % 10
        n //= 10
    return r

######################
# ---- GRID Fns ---- #
######################
def isValid(i, j, n, m):
    return i >= 0 and i < n and j >= 0 and j < m

def print_grid(grid):
    for line in grid:
        print(" ".join(map(str,line)))

######################
# ---- MISC Fns ---- #
######################
def kadane(a,size):
    max_so_far = 0
    max_ending_here = 0

    for i in range(0, size):
        max_ending_here = max_ending_here + a[i]
        if (max_so_far < max_ending_here):
            max_so_far = max_ending_here

        if max_ending_here < 0:
            max_ending_here = 0
    return max_so_far

def prefixSum(arr):
    for i in range(1, len(arr)):
        arr[i] = arr[i] + arr[i-1]
    return arr

def ceil(n, d):
    if n % d == 0:
        return n // d
    else:
        return (n // d) + 1

def _abs(a, b):
    return int(abs(a - b))

def evenodd(l):
    even = [e for e in l if e & 1 == 0]
    odd = [e for e in l if e & 1]
    return (even, odd)

# INPUTS  --------------------------
# s = input().decode('utf-8').strip()
# n = int(input())
# l = list(map(int, input().split()))
# t = int(input())
# for _ in range(t):

class Team:
    def __init__(self, name):
        self.name = name
        self.wins = 0
        self.draw = 0
        self.lost = 0
        self.goals = 0
        self.missed = 0
        self.games = []
        self.score = 0

    def computeScore(self):
        self.score = self.wins*3 + self.draw
        self.diff = self.goals - self.missed

    def __repr__(self):
        return("{}: s:{} g:{} m:{}".format(self.name, self.score, self.goals, self.missed))

    def __lt__(self, other):
        if self.score < other.score:
            return True
        elif self.score > other.score:
            return False
        else:
            st = self.goals - self.missed
            ot = other.goals - other.missed
            if st < ot:
                return True
            elif st > ot:
                return False
            else:
                if self.goals < other.goals:
                    return True
                elif self.goals > other.goals:
                    return False
                else:
                    if self.name > other.name:
                        return True
                    else:
                        return False

m = {}
teams = set()
for _ in range(5):
    s = input().decode('utf-8').strip()
    a, b, scores = s.split(" ")
    ga, gb = list(map(int, scores.split(":")))

    teams.add(a)
    teams.add(b)

    if a not in m:
        m[a] = Team(a)
    if b not in m:
        m[b] = Team(b)

    m[a].games.append(b)
    m[b].games.append(a)
    m[a].goals += ga
    m[a].missed += gb
    m[b].goals += gb
    m[b].missed += ga

    if ga > gb:
        m[a].wins += 1
        m[b].lost += 1
    elif ga < gb:
        m[a].lost += 1
        m[b].wins += 1
    else:
        m[a].draw += 1
        m[b].draw += 1

tarr = []
lastmatch = None
for t in m.keys():
    if len(m[t].games) == 2 and m[t].name != 'BERLAND':
        lastmatch = t
    m[t].computeScore()
    tarr.append(m[t])
tarr = sorted(tarr)

if tarr[2].name == "BERLAND" or tarr[3].name == "BERLAND":
    print("1:0")
    exit()

second = tarr[2]
if second.score > m['BERLAND'].score + 3:
    print('IMPOSSIBLE')
    exit()
elif m['BERLAND'].score + 3 > second.score:
    print("1:0")
    exit()
else:
    m['BERLAND'].wins += 1
    result = []
    for i in range(1, 100):
        for j in range(0, i):
            m['BERLAND'].goals += i
            m['BERLAND'].missed += j
            m[lastmatch].goals += j
            m[lastmatch].missed += i
            m['BERLAND'].computeScore()

            r = sorted([m[k] for k in m.keys()])
            #print(r)
            if r[2].name == "BERLAND" or r[3].name == "BERLAND":
                st = str(i)+":"+str(j)
                result.append((i-j, i, j))

            m['BERLAND'].goals -= i
            m['BERLAND'].missed -= j
            m[lastmatch].goals -= j
            m[lastmatch].missed -= i
            m['BERLAND'].computeScore()

    if not len(result):
        print('IMPOSSIBLE')
        exit()

    fr = sorted(result, key=lambda x: (x[0], x[2]))
    d, i, j = fr[0]
    print(str(i)+":"+str(j))
