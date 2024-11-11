# -*- coding: utf-8 -*-
"""
Created on Mon Sep  7 21:38:40 2020

@author: Dark Soul
"""
[l,r]=list(map(int,input().split()))

if l==r:
    print(0)
else:
    a=bin(l)
    b=bin(r)
    a=list(a[2:])
    b=list(b[2:])
    d=0
    if len(a)!=len(b):
        d=len(b)-len(a)
        acta=['0']*d
        for j in a:
            acta.append(j)
        a=acta
    flag=0
    sol=len(b)
    pos=-1
    for i in range(len(b)-1,-1,-1):
        if a[i]!=b[i]:
            pos=sol-i
    if pos!=-1:
        sol=pos
    
    print((2**sol)-1)