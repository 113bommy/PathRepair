# -*- coding: utf-8 -*-
"""
Created on Mon Oct  5 02:58:30 2020

@author: Dark Soul
"""

t=int(input(''))
a=list(map(int,input().split()))
ans=0
for i in range(t):
    if a[i]!=a[0]:
        ans=max(ans,i)
    if a[i]!=a[t-1]   :
        ans=max(ans,t-1-i)
print(ans)