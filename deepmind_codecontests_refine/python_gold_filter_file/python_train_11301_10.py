#   In this template you are not required to write code in main

import sys
inf = float("inf")

#from cmath import sqrt
#from collections import deque, Counter, OrderedDict,defaultdict
#from heapq import nsmallest, nlargest, heapify,heappop ,heappush, heapreplace
from math import ceil,floor,log,sqrt,factorial,pow,pi,gcd
#from bisect import bisect_left,bisect_right

abc='abcdefghijklmnopqrstuvwxyz'
abd={'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}
mod,MOD=1000000007,998244353
vow=['a','e','i','o','u']
dx,dy=[-1,1,0,0],[0,0,1,-1]



def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def input(): return sys.stdin.readline().strip()

l1,r1,l2,r2,k=get_ints()

mini1=max(l1,l2)
mini2=min(r1,r2)
ans=mini2-mini1+1
if mini1<=k<=mini2:
    ans-=1
print(max(ans,0))
