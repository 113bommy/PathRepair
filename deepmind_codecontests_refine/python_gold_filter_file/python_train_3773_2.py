# -*- coding: utf-8 -*-
"""
Created on Mon Jun 15 13:22:05 2020

@author: Mridul Garg
"""
import math
q = int(input())
for _ in range(q):
    n = int(input())
    A = list(map(int, input().split(" ")))
    
    A.sort()
    a, b = [], []
    ln = math.ceil(n/2)
    for i in range(ln):
        a.append(A[i])
    
    for i in range(ln, n):
        b.append(A[i])
        
#    print(a, b)
    p1, p2 = 0, len(a)-1
    ans = []
    while p1 < len(b) or p2>=0:
        ans.append(a[p2])
        p2 -= 1
        
        if p1 < len(b):
            ans.append(b[p1])
            p1 += 1
            
    for i in ans:
        print(i, end = " ")
    print()
                
                