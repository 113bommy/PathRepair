# -*- coding: utf-8 -*-
"""
Created on Thu Oct 15 15:36:21 2020

@author: 86198
"""

n,h=map(int,input().split());x=0
listi=[int(i)for i in input().split()]
for i in listi:
    if i<=h:
        x=x+1
    else:
        x=x+2
print(x)
        