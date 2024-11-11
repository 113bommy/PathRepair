#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 26 19:26:22 2020

@author: wwy
"""

t = int(input())
for i in range(t):
    n = int(input())
    if n%2 == 0:
        x = n - 1 - n/2
    else:
        x = n - (n+1)/2
    print(int(x))
