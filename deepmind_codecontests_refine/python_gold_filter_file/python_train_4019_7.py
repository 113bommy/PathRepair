# -*- coding: utf-8 -*-
"""
Created on Mon Aug 17 02:49:27 2020

@author: Dark Soul
"""

[n,f]=list(map(int, input().split()))
arr=[]
s=0
for i in range(n):
    arr.append(list(map(int, input().split())))
    s+=min(arr[i][0],arr[i][1])

narr=[]
for i in arr:
    if i[0]>=i[1]:
        continue
    else:
        narr.append(min(2*i[0],i[1])-i[0])
narr.sort(reverse=True)
s=s+sum(narr[0:f])
print(s)   