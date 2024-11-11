import math
import itertools
getInputList = lambda : list(input().split())
getInputIntList = lambda : list(map(int,input().split()))

n = int(input())
m = int(input())
a = getInputIntList()
b = getInputIntList()

w = a+b
left = 0
right = (10**9)+2
best = -1
"""
2
12
11 8
7 5
11 5 8 7
"""
while left <= right:
    md = (left + right)//2
    iw = md + m
    for i in w:
        iw -= iw/i
    if iw >= m:
        best = md
        right = md -1
    else:
        left = md + 1
left = 0
right = 10**6
ans = best
while left <= right:
    md = (left + right)//2
    iw = (md/10**6) + m + best -1
    for i in w:
        iw -= iw/i
    if iw >= m:
        ans = (md/10**6) + best -1
        right = md-1
    else:
        left = md+1
print(min(best,ans))
