import sys
input = sys.stdin.readline
# def mp():return map(int,input().split())
# def lmp():return list(map(int,input().split()))
# def mps(A):return [tuple(map(int, input().split())) for _ in range(A)]
import math
import bisect
from copy import deepcopy as dc
from itertools import accumulate
from collections import Counter, defaultdict, deque
def ceil(U,V):return (U+V-1)//V
def modf1(N,MOD):return (N-1)%MOD+1
inf = int(1e20)
mod = int(1e9+7)

t = int(input())
for _ in range(t):
    n = int(input())
    u = list(map(int,input().split()))
    s = list(map(int,input().split()))
    uni = [[] for i in range(n+1)]
    for i in range(n):
        uni[u[i]].append(s[i])
    for i in uni:
        i.sort(reverse=True)
    for i in range(n+1):
        uni[i] = list(accumulate(uni[i]))
    uc = list(Counter(u).items())
    ans = [0]*(n+1)
    for i,j in uc:
        for k in range(1,n+1):
            if j >= k:
                ans[k] += uni[i][j-(j%k)-1]
            else:
                break
    print(*ans[1:])







