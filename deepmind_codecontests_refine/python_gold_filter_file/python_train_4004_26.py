# Template 1.0
import sys, re, math
from collections import deque, defaultdict, Counter, OrderedDict
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from heapq import heappush, heappop, heapify, nlargest, nsmallest
def STR(): return list(input())
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def list2d(a, b, c): return [[c] * b for i in range(a)]
def sortListWithIndex(listOfTuples, idx):   return (sorted(listOfTuples, key=lambda x: x[idx]))
def sortDictWithVal(passedDic):
    temp = sorted(passedDic.items(), key=lambda kv: (kv[1], kv[0]))[::-1]
    toret = {}
    for tup in temp:
        toret[tup[0]] = tup[1]
    return toret
def sortDictWithKey(passedDic):
    return dict(OrderedDict(sorted(passedDic.items())))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

def s(num):
    temp = str(num)
    toret = 0
    for ch in temp:
        toret+=int(ch)
    return toret

a,b,c = MAP()
ans = 0
l = []
for k in range(1, 81):
    x = b*k**a + c
    if(x>0 and x<10**9):
        if(s(x)==k):
            ans+=1
            l.append(x)

print(ans)
if(ans!=0):
    print(*l)