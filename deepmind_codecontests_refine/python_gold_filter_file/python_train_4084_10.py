# -*- coding: utf-8 -*-
"""
Created on Fri Oct 23 03:11:24 2020

@author: Dark Soul
"""

n=int(input(''))
arr=list(map(int,input().split()))
arr.sort(reverse=True)
suff=[0]*(n+1)
pre=[0]*n
mx=-100000000000000
ind=-1
suff[n-1]=(~arr[n-1])
for i in range(n-2,-1,-1):
    suff[i]=(suff[i+1])&(~arr[i])
for i in range(n):
    
    if i==0:
        ase=(~arr[0])
        now=arr[i]&suff[1]
    else:
        now=arr[i]
        if i!=n-1:
            now=arr[i]&suff[i+1]
        
        now=now&ase
        ase=ase&(~arr[i])
    if now>mx:
        mx=now
        ind=i
for i in range(n):
    
    if i==0:
        ase=(~arr[0])
        now=arr[i]&suff[1]
    else:
        now=arr[i]
        if i!=n-1:
            now=arr[i]&suff[i+1]
        
        now=now&ase
        ase=ase&(~arr[i])
    if now>mx:
        mx=now
        ind=i

temp=arr[ind]
arr[ind]=arr[0]
arr[0]=temp
print(*arr)
