import bisect, copy, heapq, math, sys
from collections import *
from functools import lru_cache
from itertools import accumulate, combinations, permutations, product
def input():
    return sys.stdin.readline()[:-1]
def ruiseki(lst):
    return [0]+list(accumulate(lst))
def celi(a,b):
    return -(-a//b)
sys.setrecursionlimit(5000000)
mod=pow(10,9)+7
al=[chr(ord('a') + i) for i in range(26)]
direction=[[1,0],[0,1],[-1,0],[0,-1]]

s=list(map(int,list(input())))
n=len(s)
# print(s)
if s[-1]==1 or s[0]==0:
    print(-1)
    quit()

for i in range(n-1):
    if s[i]!=s[-2-i]:
        print(-1)
        quit()
s[-1]=1
now=n
for i in range(n-1)[::-1]:
    print(i+1,now)
    if s[i]==1:
        now=i+1
