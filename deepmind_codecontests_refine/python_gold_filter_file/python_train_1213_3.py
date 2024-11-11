# -*- coding: utf-8 -*-
"""
Created on Tue Aug 18 23:09:07 2020

@author: Dark Soul
"""
MAX=10000000
[n,A,B]=list(map(int, input().split()))
arr=list(map(int, input().split()))
s=arr[0]

arr[0]=-1
arr.sort()
arr[0]=s
sm=0
sol=MAX
for j in range(n):
    sm+=arr[j]
    if (s*A/sm)>=B:
        sol=min(sol,n-j-1)
        
print(sol)