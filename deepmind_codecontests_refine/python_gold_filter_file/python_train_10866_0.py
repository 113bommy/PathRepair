#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Aug  1 18:08:37 2020

@author: divyarth
"""

import sys
import heapq
from collections import deque
from collections import defaultdict
input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(100000)
def PRINT(lst,sep=' '): print(sep.join(map(str,lst)))
I=lambda : list(map(int,input().split(' ')))

def solve(lst,queries):
    
    n=len(lst)
    arr_f=[1]
    cur_max=1
    for i in range(n-2,-1,-1):
        if lst[i]<=lst[i+1]:
            cur_max+=1
        else:
            cur_max=1
        arr_f.append(cur_max)
    arr_f.reverse()
        
    arr_b=[1]
    cur_max=1
    for i in range(n-1):
        if lst[i+1]<=lst[i]:
            cur_max+=1
        else:
            cur_max=1
        arr_b.append(cur_max)
    
    ans=[]
    for l,r in queries:
        l=l-1
        r=r-1
        if arr_f[l]+arr_b[r]>=r-l+1:
            ans.append('Yes')
        else:
            ans.append('No')
    PRINT(ans,sep='\n')
    
n,m=I()
lst=I()
queries=[I() for i in range(m)]
solve(lst,queries)