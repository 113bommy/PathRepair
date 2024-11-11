from __future__ import print_function
import sys
import math
import os.path
import random
from copy import deepcopy
from functools import reduce
from collections import Counter, ChainMap, defaultdict
from itertools import cycle, chain
from queue import Queue, PriorityQueue
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, nlargest, nsmallest
import bisect
from statistics import mean, mode, median, median_low, median_high
# CONFIG
sys.setrecursionlimit(1_000_000_000)
# LOG 
def log(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
# INPUT
def ni():
    return map(int, input().split())
def nio(offset):
    return map(lambda x: int(x) + offset, input().split())
def nia():
    return list(map(int, input().split()))
# CONVERT
def toString(aList, sep=" "):
    return sep.join(str(x) for x in aList)
def toMapInvertIndex(aList):
    return {k: v for v, k in enumerate(aList)}
# SORT
def sortId(arr):
    return sorted(range(arr), key=lambda k: arr[k])
# MATH
def gcd(a,b):
    while b:
        a, b = b, a % b
    return a
# MAIN

a = input()
b = input()

n = len(a)

count = 0

pre = 0
for i in range(1,n):
    if (i>pre):
        if a[pre:i+1] == "00" and b[pre:i+1] == "00":
            count += 1
            pre = i+1
            if i < n-1:
                if a[i+1] == "0" and b[i+1] == "0":
                    count += 1
                    pre = i+2
        elif a[pre:i+1] == "0X" and b[pre:i+1] == "00":
            count += 1
            pre = i+1
        elif a[pre:i+1] == "00" and b[pre:i+1] == "0X":
            count += 1
            pre = i+1  
        elif a[pre:i+1] == "X0" and b[pre:i+1] == "00":
            count += 1
            pre = i+1
        elif a[pre:i+1] == "00" and b[pre:i+1] == "X0":
            count += 1
            pre = i+1
        else:
            pre = i

                
            

print(count)
