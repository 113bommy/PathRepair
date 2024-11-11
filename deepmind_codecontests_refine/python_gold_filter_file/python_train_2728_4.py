# -*- coding: utf-8 -*-
"""
Created on Mon Dec 30 23:57:15 2019

@author: ASUS
"""

t=int(input())
for i in range(t):
    s=int(input())
    flag=0
    arr=list(map(int,input().split()))
    for j in range(s-1):
        if abs(arr[j]-arr[j+1])>=2:
            print("YES")
            print(j+1,j+2)
            flag=1
            break
    if flag==0:
        print("NO")