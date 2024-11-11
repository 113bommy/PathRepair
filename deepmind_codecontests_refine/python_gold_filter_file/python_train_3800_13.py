# -*- coding: utf-8 -*-
"""
Created on Sat Nov 16 22:17:37 2019

@author: LV
"""

n, x = map(int, input().split())
count = 0
for i in range(1, n + 1):
    if(n * i >= x and x % i == 0):
        count += 1
print(count)