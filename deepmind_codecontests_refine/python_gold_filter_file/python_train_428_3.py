# -*- coding: utf-8 -*-
"""
Created on Sat Mar 23 02:55:02 2019

@author: screamLab
"""

t = int(input())

for v in range(t):
    s = int(input())
    string = input()
    if string[0] == '>' or string[-1] == '<':
        print(0)
    else:
        ans1 = 0
        ans2 = 0
        for i in range(s):
            if string[i] == '>':
                break
            ans1 += 1
        for j in range(s-1,-1,-1):
            if string[j] == '<':
                break
            ans2 += 1
        print(min(ans1,ans2))