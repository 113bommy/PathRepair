 ######      ###      #######    #######    ##      #     #####        ###     ##### 
 #     #    #   #          #        #       # #     #    #     #      #   #     ###  
 #     #   #     #        #         #       #  #    #   #       #    #     #    ###  
 ######   #########      #          #       #   #   #   #           #########    #   
 ######   #########     #           #       #    #  #   #           #########    #   
 #     #  #       #    #            #       #     # #   #    ####   #       #    #   
 #     #  #       #   #             #       #      ##   #    #  #   #       #        
 ######   #       #  #######     #######    #       #    #####  #   #       #    #   
 
from __future__ import print_function # for PyPy2
# from itertools import permutations
# from functools import cmp_to_key  # for adding custom comparator
# from fractions import Fraction
# from collections import *
from sys import stdin
# from bisect import *
from heapq import *
from math import log2, ceil, sqrt, gcd, log
 
g   = lambda : stdin.readline().strip()
gl  = lambda : g().split()
gil = lambda : [int(var) for var in gl()]
gfl = lambda : [float(var) for var in gl()]
gcl = lambda : list(g())
gbs = lambda : [int(var) for var in g()]
rr = lambda x : reversed(range(x)) 
mod = int(1e9)+7
inf = float("inf")
# range = xrange

n, m = gil()
if n <= m:
    print(n)
    exit()

l, r = 1, int(1e18)
ans = -1
n -= m

while l <= r:
    mid = (l+r)//2
    if n <= (mid*(mid+1))//2:
        ans = mid
        r = mid - 1
    else:
        l = mid + 1

print(ans+m)