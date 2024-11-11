import sys, io, os, re
from bisect import bisect, bisect_left, bisect_right, insort, insort_left, insort_right
from pprint import pprint
from math import sin, cos, pi, radians, sqrt, floor
from copy import copy, deepcopy
from collections import deque
from fractions import gcd
from functools import reduce
from itertools import groupby
from heapq import heapify, heappush, heappop

n1 = lambda: int(sys.stdin.readline().strip())
nn = lambda: list(map(int, sys.stdin.readline().strip().split()))
f1 = lambda: float(sys.stdin.readline().strip())
fn = lambda: list(map(float, sys.stdin.readline().strip().split()))
s1 = lambda: sys.stdin.readline().strip()
sn = lambda: list(sys.stdin.readline().strip().split())
nl = lambda n: [n1() for _ in range(n)]
fl = lambda n: [f1() for _ in range(n)]
sl = lambda n: [s1() for _ in range(n)]
nm = lambda n: [nn() for _ in range(n)]
fm = lambda n: [fn() for _ in range(n)]
sm = lambda n: [sn() for _ in range(n)]

def array1(n, d=0): return [d] * n
def array2(n, m, d=0): return [[d] * m for x in range(n)]
def array3(n, m, l, d=0): return [[[d] * l for y in xrange(m)] for x in xrange(n)]

def ldec(A, d=1): return map(lambda x: x - d, A)

def solve(N, A, S):
    dp = [0]

    for i in range(N-1, -1, -1):
        #print(i, dp)
        ai = A[i]
        if S[i] == "0":
            # Pattern 1 -> TLE
            #dp += [x^A[i] for x in dp if x^A[i] not in dp]
            
            # Pattern 2 -> TLE
            #for x in dp:
            #    a = x ^ A[i]
            #    if bisect_left(dp, a) == bisect_right(dp, a):
            #        insort(dp, a)

            for d in dp:
                if ai > ai^d: ai ^= d
            if ai: dp.append(ai)

        if S[i] == "1":
            #if A[i] not in dp:
            #    print("1")
            #    return

            for b in dp:
                if ai > ai^b: ai ^= b

            if ai != 0:
                print("1")
                return

    print("0")

T = n1()
for _ in range(T):
    N = n1()
    A = nn()
    S = s1()
    solve(N, A, S)
