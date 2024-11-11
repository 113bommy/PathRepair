# -*- coding: utf-8 -*-
"""
Created on Mon Sep 28 14:55:19 2020

@author: Dark Soul
"""

n=int(input(''))
a=list(map(int,input().split()))
b=list(map(int,input().split()))

mxsol=min(a[0],b[1])+min(a[1],b[2])+min(a[2],b[0])
mn=0
if a[0]>b[2]+b[0]:
    mn=max(mn,a[0]-b[2]-b[0])
if a[1]>b[1]+b[0]:
    mn=max(mn,a[1]-b[1]-b[0])
if a[2]>b[2]+b[1]:
    mn=max(mn,a[2]-b[2]-b[1])
    



print(mn,mxsol)



