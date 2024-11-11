# -*- coding: utf-8 -*-
"""
Created on Mon Nov  2 16:05:33 2020

@author: 章斯岚
"""
import math
t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    print(math.ceil(k*(n/(n-1)))-1)