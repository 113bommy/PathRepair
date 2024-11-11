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
    N,W=MI()
    WV=LLIN(N)
    W0 = WV[0][0]
    for i,(w,v) in enumerate(WV):
        WV[i][0] = w-W0
    WV.sort(key=lambda x: x[1], reverse=True)
    cumsum = [0]*N
    for i,(w,v) in enumerate(WV):
        cumsum[i]=cumsum[i-1]+v

    dp = [[0]*(N*3+1) for _ in range(N+1)]
    for i in range(N):
        for k in range(1,N+1)[::-1]:
            for w in range(N*3+1):
                if w>=WV[i][0]:
                    dp[k][w] = max(dp[k][w], dp[k-1][w-WV[i][0]] + WV[i][1])

    ans = 0 
    for k in range(1,N+1):
        W_k = W-W0*k
        if W_k>=N*3:
            ans = max(ans, cumsum[k-1])
            continue
        if W_k<0:
            break   
        ans = max(ans, dp[k][W_k])
    print(ans)



if __name__ == '__main__':
    main()