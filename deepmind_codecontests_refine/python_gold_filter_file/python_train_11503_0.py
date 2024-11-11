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
from collections import *
from sys import stdin
# from bisect import *
from heapq import *
from math import *
 
g   = lambda : stdin.readline().strip()
gl  = lambda : g().split()
gil = lambda : [int(var) for var in gl()]
gfl = lambda : [float(var) for var in gl()]
gcl = lambda : list(g())
gbs = lambda : [int(var) for var in g()]
rr = lambda x : reversed(range(x)) 
mod = int(1e9)+7
inf = float("inf")

n, m = gil()
h = [gil() for _ in range(m)]
ans = max(h[0][1], h[-1][1])

for i in range(1, m):
    xd, yd = h[i][0]-h[i-1][0], abs(h[i][1]-h[i-1][1]) 
    if yd > xd :print('IMPOSSIBLE');exit()
    ans = max(ans, max(h[i][1], h[i-1][1]) + ((xd-yd)//2) , h[i][1])
    # print(int(ceil((xd-yd)/2)))

ans = max(ans, sum(h[0])-1, h[-1][1] - h[-1][0] + n)

print(ans)