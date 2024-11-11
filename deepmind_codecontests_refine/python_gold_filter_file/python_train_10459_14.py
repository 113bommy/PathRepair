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

a, b = gil()
if a <= b:
    print('0' if a < b else 'infinity')
    exit()

a -= b
ans = 0

for i in range(1, int((sqrt(a)))+1):
    if a%i:continue
    j = a//i
    if min(i, j) > b and i != j:
        # print(i, j, end= ' ')
        ans += 2
    elif max(i, j) > b:
        # print(max(i, j), end= ' ')
        ans += 1

print(ans)