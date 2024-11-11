# -*- coding: utf-8 -*-
"""
Created on Fri Aug 14 20:27:10 2020

@author: Dark Soul
"""

t=int(input(''))
arr=[]
for i in range(t):
    int(input(''))
    arr.append(list(map(int,input().split())))
for i in arr:
    n=len(i)
    s=i[0]+i[1]
    flag=0
    for j in range(2,n):
        if i[j]>=s:
            print(1,2,j+1)
            flag=1
            break
    if flag==0:
        print(-1)