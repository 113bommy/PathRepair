# Template 1.0
import sys, re, math
from collections import deque, defaultdict, Counter, OrderedDict
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, gcd
from heapq import heappush, heappop, heapify, nlargest, nsmallest
def STR(): return list(input())
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def list2d(a, b, c): return [[c] * b for i in range(a)]
def sortListWithIndex(listOfTuples, idx):   return (sorted(listOfTuples, key=lambda x: x[idx]))
def sortDictWithVal(passedDic):
    temp = sorted(passedDic.items(), key=lambda kv: (kv[1], kv[0]))
    toret = {}
    for tup in temp:
        toret[tup[0]] = tup[1]
    return toret
def sortDictWithKey(passedDic):
    return dict(OrderedDict(sorted(passedDic.items())))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

def check(idx):
    up = down = 0
    a1,a2,a3 = sorted(a[idx:idx+3])
    return (a1<=a2<=a3 and a2>=k)


t = INT()

while(t!=0):
    n,k = MAP()

    a = LIST()

    if(k in a):
        flag = 1
    else:
        flag = 0
    if(flag==1):
        for patchStart in range(n-2):
            if(check(patchStart)):
                flag = 1
                break
            else:
                flag=0
                continue

        if(n==2):
            foo = 0
            for el in a:
                if(el>=k):
                    foo+=1
            if(foo==2):
                print("yes")
            else:
                print("no")
        else:
            if (flag == 0):
                print("no")
            else:
                print("yes")

    else:
        print("no")



    t-=1