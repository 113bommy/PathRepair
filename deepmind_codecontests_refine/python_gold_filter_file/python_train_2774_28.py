# -*- coding: utf-8 -*-
"""
Created on Wed May 29 16:02:14 2019

@author: avina
"""

n, k = map(int, input().split())
l= list(map(int, input().split()))
mins = n+1000; index = 0

for i in range(k):
    if n%l[i] <= mins:
        mins = n%l[i]
        index = i+1
print(index,n//l[index-1])