import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from bisect import bisect_left as bl, bisect_right as br, insort
from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
from itertools import permutations,combinations
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def out(var) : sys.stdout.write(str(var)+'\n')
from decimal import Decimal
#from fractions import Fraction
sys.setrecursionlimit(100000)
INF = float('inf')
mod = 10**9 + 7


for t in range(int(data())):
    data()
    n,m=mdata()
    M=[mdata() for i in range(m)]
    M.sort(key=lambda x:(x[1],x[0]))
    if m%2:
        out("NO")
    else:
        ans="YES"
        for i in range(0,m,2):
            if (M[i][0]+M[i+1][0]+M[i][1]+M[i+1][1])%2==0 or (i+2<m and M[i+1][1]==M[i+2][1]):
                ans="NO"
                break
        out(ans)









