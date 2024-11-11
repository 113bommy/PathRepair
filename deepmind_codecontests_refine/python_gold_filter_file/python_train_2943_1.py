import sys, math
import io, os
data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from bisect import bisect_left as bl, bisect_right as br, insort
from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
#from itertools import permutations,combinations
#def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def out(var) : sys.stdout.write(str(var)+'\n')
from decimal import Decimal
from fractions import Fraction
#sys.setrecursionlimit(100000)
INF = float('inf')
mod = int(1e9)+7


n,m=mdata()
dp=[[0]*m for i in range(n)]
mat=[]
for i in range(n):
    mat.append(data())
ans=n*m
for i in range(1,n-1):
    for j in range(1,m-1):
        if mat[i-1][j]==mat[i][j-1]==mat[i][j]:
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1
for i in range(n-2,0,-1):
    for j in range(m-2,0,-1):
        if mat[i+1][j]==mat[i][j+1]==mat[i][j]:
            dp[i][j]=min(dp[i][j],min(dp[i+1][j],dp[i][j+1])+1)
        else:
            dp[i][j]=0
        ans+=dp[i][j]
out(ans)