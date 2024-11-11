# -*- coding: utf-8 -*-
"""
Created on Wed Apr 14 09:56:34 2021

@author: MridulSachdeva
"""


n = int(input())
s = list(map(int, input().split()))

if n <= 2:
    print(n)
else:
    max1 = 2
    temp = 2
    for i in range(2, n):
        if s[i] == s[i-1] + s[i-2]:
            temp += 1
            if temp > max1:
                max1 = temp
        else:
            temp = 2
    print(max1)