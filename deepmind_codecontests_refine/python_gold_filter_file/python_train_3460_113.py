from math import ceil,gcd,floor
from collections import deque,defaultdict 
from heapq import heappush as hpush,heappop as hpop, heapify
from functools import lru_cache
import sys
# input = sys.stdin.buffer.readline
inf=float("inf")

def inpi(): return(int(input()))
def inpa(): return(list(map(int,input().split())))
def inp(): s = input();return(list(s))
def inpv(): return(map(int,input().split()))


testcase=int(input())
for test in range(testcase):
	a,b,c,d=inpv()
	print(b,c,c)