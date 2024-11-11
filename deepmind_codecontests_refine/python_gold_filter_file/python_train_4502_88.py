# -*- coding: utf-8 -*-
"""
Created on Tue Oct  6 09:32:29 2020

@author: feibiaodi
"""

n=int(input())
for i in range(0,n):
    d=int(input())
    if d==1 or d==2:
        print(0)
    if d>=3 and d%2==0:
        print(int((d-2)/2))
    if d>=3 and d%2!=0:
        print(int((d-1)/2))