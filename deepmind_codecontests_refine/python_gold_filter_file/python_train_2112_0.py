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
#from decimal import Decimal
#from fractions import Fraction
#sys.setrecursionlimit(100000)
INF = 10**9
mod = int(1e9)+7


def construct(BIT,arr):
    for i in range(len(arr)):
        BIT[i+1]=arr[i]

def updateBIT(BIT,v, w):
    while v <= n:
        BIT[v] += w
        v += (v & (-v))


def getvalue(BIT,v):
    ANS = 0
    while v != 0:
        ANS += BIT[v]
        v -= (v & (-v))
    return ANS


def bisect_on_BIT(BIT,x):
    if x <= 0:
        return 0
    ANS = 0
    h = 1 << (n - 1)
    while h > 0:
        if ANS + h <= n and BIT[ANS + h] < x:
            x -= BIT[ANS + h]
            ANS += h
        h //= 2
    return ANS + 1


def update(BIT, l, r, n, val):
    updateBIT(BIT, l, val)
    updateBIT(BIT, r + 1, -val)


n=int(input())
BIT = [0]*(n+1)
stack=[]
ans=[0]*n
cnt=0
a=[data().split() for i in range(2*n)]
for i in range(2*n):
    if a[i][0]=='+':
        stack.append([cnt,0])
        cnt+=1
    else:
        x=int(a[i][1])
        if stack and (n-x)-(getvalue(BIT,n)-getvalue(BIT,x))>=len(stack)-1 and stack[-1][1]<x:
            p,q=stack.pop()
            ans[p]=x
            updateBIT(BIT,x,1)
            if stack:
                stack[-1][1]=max(stack[-1][1],q,x)
        else:
            out("NO")
            exit()
if stack:
    out("NO")
    exit()
out("YES")
outl(ans)