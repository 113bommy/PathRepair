#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Apr 10 15:18:05 2017

@author: lawrenceylong
"""

n = int(input())

possible = [4,6,8]

for item in possible:
    a = n-item
    count = 0
    for i in range(2,a):
        if a%i == 0:
            count = 1
            break
    if count == 1:
        print(item,a)
        break