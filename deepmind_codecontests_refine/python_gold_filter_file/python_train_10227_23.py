#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat May  1 22:13:22 2021

@author: test
"""

t=int(input())
for _ in range(t):
    n,k=[int(x) for x in input().split()]
    if n>=k*k and n%2==k%2:
        print("YES")
    else:
        print("NO")