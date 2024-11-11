# -*- coding: utf-8 -*-
"""
Created on Tue Mar 10 22:10:44 2020

@author: DELL
"""
o=input()
v='aeiouyAEIOUY'
for i in range(len(o)-1,-1,-1):
    k=o[i]
    if k.isalpha():
        if k in v:
            print('YES')
        else:
            print('NO')
        break