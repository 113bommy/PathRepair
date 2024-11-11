import sys
from heapq import heappop
from heapq import heappush
from heapq import heapify
from bisect import insort
from bisect import bisect_right
from bisect import bisect_left
from sys import stdin,stdout
from collections import defaultdict, deque
from math import log2, ceil, floor

inp=lambda : int(input())
sip=lambda : input()
mulip =lambda : map(int,input().split())
lst=lambda : list(map(int,input().split()))
slst=lambda: list(sip())
arr2d= lambda x: [[int(j) for j in input().split()] for i in range(x)]
odds = lambda l: len(list(filter(lambda x: x%2!=0, l)))
evens = lambda l: len(list(filter(lambda x: x%2==0, l)))
mod = pow(10,9)+7
#-------------------------------------------------------
Judge = 0
if Judge:
    sys.stdin = open("input.in",'r')
    #sys.stdout = open("output.in",'w')

ff = inp()
b = inp()
c = inp()
tie = inp()
e = inp()
f = inp()
ss = min(b,c)

if e>f:
	print(e*min(ff,tie)+f*min(max(tie-ff,0),ss))
elif e==f:
	print(e*min(tie,ss+ff))
else:
	print(e*min(max(tie-ss,0),ff)+f*min(ss,tie))












        





    

