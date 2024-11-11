#
# 　　  ⋀_⋀　 
#　　  (･ω･)  
# .／ Ｕ ∽ Ｕ＼
#  │＊　合　＊│
#  │＊　格　＊│ 
#  │＊　祈　＊│ 
#  │＊　願　＊│ 
#  │＊　　　＊│ 
#      ￣
#
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
    N,K=MI()
    
    imos2d = [[0]*(2*K+1) for _ in range(2*K+1)]
    
    def get_cord(x):
        if x<K-1:
            return [(0,x+1), (x+K+1,2*K)]
        else:
            return [(x-K+1,x+1)]

    for _ in range(N):
        x,y,c = ST().split()
        x,y = int(x), int(y)
        if c=="W":
            x+=K
        x,y = x%(2*K), y%(2*K)
        for base in [0,K]:
            for l,r in get_cord((x+base)%(2*K)):
                for u,d in get_cord((y+base)%(2*K)):
                    imos2d[l][u] += 1
                    imos2d[l][d] -= 1
                    imos2d[r][u] -= 1
                    imos2d[r][d] += 1

    for i in range(2*K):
        for j in range(2*K+1):
            imos2d[i+1][j] += imos2d[i][j]
    
    for i in range(2*K+1):
        for j in range(2*K):
            imos2d[i][j+1] += imos2d[i][j]


    ans = 0
    for a in imos2d:
        ans = max(ans,max(a))
    print(ans)

if __name__ == '__main__':
    main()