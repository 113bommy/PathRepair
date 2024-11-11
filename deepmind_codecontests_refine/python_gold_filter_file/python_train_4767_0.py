#!usr/bin/env python3
from collections import defaultdict,deque
from heapq import heappush, heappop
from itertools import permutations
import sys
import math
import bisect
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def I(): return int(sys.stdin.readline())
def LS():return [list(x) for x in sys.stdin.readline().split()]
def S():
    res = list(sys.stdin.readline())
    if res[-1] == "\n":
        return res[:-1]
    return res
def IR(n):
    return [I() for i in range(n)]
def LIR(n):
    return [LI() for i in range(n)]
def SR(n):
    return [S() for i in range(n)]
def LSR(n):
    return [LS() for i in range(n)]

sys.setrecursionlimit(1000000)
mod = 1000000007

def solve():
    k,q = LI()
    d = LI()
    for _ in range(q):
        n,x,m = LI()
        a = [((i-1)%m)+1 for i in d]
        S = sum(a)
        r = (n-1)//k
        s = S*r+(x%m)
        for i in range((n-1)%k):
            s += a[i]
        print(n-1-(s//m))
    return

#Solve
if __name__ == "__main__":
    solve()
