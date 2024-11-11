#!/usr/bin/env python3
from collections import defaultdict,deque
from heapq import heappush, heappop
from bisect import bisect_left, bisect_right
import sys, random, itertools, math
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
sqrt = math.sqrt
def LI(): return list(map(int, input().split()))
def LF(): return list(map(float, input().split()))
def LI_(): return list(map(lambda x: int(x)-1, input().split()))
def II(): return int(input())
def IF(): return float(input())
def LS(): return list(map(list, input().split()))
def S(): return list(input().rstrip())
def IR(n): return [II() for _ in range(n)]
def LIR(n): return [LI() for _ in range(n)]
def FR(n): return [IF() for _ in range(n)]
def LFR(n): return [LI() for _ in range(n)]
def LIR_(n): return [LI_() for _ in range(n)]
def SR(n): return [S() for _ in range(n)]
def LSR(n): return [LS() for _ in range(n)]
mod = 1000000007
inf = 1e10

#solve
def solve():
    n, q = LI()
    a = LI()
    odd = [0] * n
    even = [0] * n
    def f(mid):
        return abs(a[mid] - x) < abs(a[mid - (n - mid - 1)] - x)
    for i in range(n):
        if i & 1:
            odd[i] += odd[i - 1] + a[i]
        else:
            odd[i] += odd[i - 1]
    acc = list(itertools.accumulate(a))
    for _ in range(q):
        x = II()
        ok = 0
        ng = n
        while abs(ng - ok) > 1:
            mid = (ok + ng) // 2
            if f(mid):
                ok = mid
            else:
                ng = mid
        ok = ng - (n - ng)
        ng -= 1
        ans = acc[-1] - acc[ng]
        if ok < 0:
            pass
        elif n & 1:
            ans += acc[ok]-odd[ok]
        else:
            ans += odd[ok]
        print(ans)
        
    return


#main
if __name__ == '__main__':
    solve()
