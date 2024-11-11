# -*- coding: utf-8 -*-
"""
Created on Fri Jun 21 01:02:39 2019

@author: sj
"""
def s(str,a):
    a.append(str)
    if len(str)>=10:
        return a
    s(str+'0',a)
    s(str+'1',a)
    return a
n=int(input())
a=[]
a=s('1',a)
x=len(a)
ans=0
for i in range(0,x):
    if int(a[i])<=n:
        
        ans+=1
print(ans)