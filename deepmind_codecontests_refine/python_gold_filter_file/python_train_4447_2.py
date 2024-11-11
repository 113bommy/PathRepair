import sys
sys.setrecursionlimit(10**6)
input=sys.stdin.readline
from math import floor,sqrt,factorial,hypot,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict,deque
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
from fractions import gcd
from random import randint
def ceil(a,b): return (a+b-1)//b
inf=float('inf')
mod = 10**9+7
def pprint(*A): 
    for a in A:     print(*a,sep='\n')
def INT_(n): return int(n)-1
def MI(): return map(int,input().split())
def MF(): return map(float, input().split())
def MI_(): return map(INT_,input().split())
def LI(): return list(MI())
def LI_(): return [int(x) - 1 for x in input().split()]
def LF(): return list(MF())
def LIN(n:int): return [I() for _ in range(n)]
def LLIN(n: int): return [LI() for _ in range(n)]
def LLIN_(n: int): return [LI_() for _ in range(n)]
def LLI(): return [list(map(int, l.split() )) for l in input()]
def I(): return int(input())
def F(): return float(input())
def ST(): return input().replace('\n', '')
def main():
    N,H=MI()

    """
    H=1のとき
    1 2 1 0 もvalid
    """
    if(N > H*(H+1)//2):
        def calc(h,N):
            tmp = h*(h+1)//2 + (h-1)*h//2
            tmp -= (H-1)*H//2
            N -= tmp
            res = h + (h-H)
            res += ceil(N,h)
            return res
        def is_ok(h):
            tmp = h*(h+1)//2 + (h-1)*h//2
            tmp -= (H-1)*H//2
            return tmp <= N
        
        ok = H+1
        ng = 10**18
        while ng-ok>1:
            mid = (ng+ok)//2
            if(is_ok(mid)):
                ok = mid
            else:
                ng = mid
        print(calc(ok,N))
    else:
        def is_ok(h):
            return N >= h*(h+1)//2

        def calc(h):
            M = N
            res = h
            M -= h*(h+1)//2
            res += ceil(M,h)
            return res
        
        ok = 0
        ng = H+1
        while ng-ok>1:
            mid = (ng+ok)//2
            if(is_ok(mid)):
                ok = mid
            else:
                ng = mid
        print(calc(ok))
if __name__ == '__main__':
    main()