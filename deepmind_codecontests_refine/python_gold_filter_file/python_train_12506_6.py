# -*- coding: utf-8 -*-
"""
Created on Tue Feb 26 18:18:15 2019

@author: screamLab
"""

q = int(input())
for i in range(q):
    n = int(input())
    s = input()
    if(len(s) == 2 and s[0] >= s[1]):
        print('NO')
    else:
        print('YES')
        print('2')
        print(s[0],s[1::])