# -*- coding: utf-8 -*-
"""
Created on Wed Nov 11 20:01:17 2020

@author: 86183
"""

n=int(input())
t=[]
m=2
for i in range(n):
    t.append([int(x) for x in input().split()])
for i in range(1,n-1):
    if t[i][0]-t[i][1]>t[i-1][0]:
        m+=1
    elif t[i][0]+t[i][1]<t[i+1][0]:
        m+=1
        t[i][0]=t[i][0]+t[i][1]
print([1,m][n>1])