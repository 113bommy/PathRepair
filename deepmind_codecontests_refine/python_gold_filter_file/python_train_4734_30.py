# -*- coding: utf-8 -*-
"""
Created on Wed Apr 15 02:43:23 2020

@author: odraodE
"""

'''testo dell'esercizio https://codeforces.com/problemset/problem/49/A'''

a=input()

vocali={'A','a','E','e','I','i','O','o','U','u','Y','y'}

for x in range(1,len(a)+1):
    if a[-x] >='A' and a[-x] <= 'z':
        if a[-x] in vocali:
            print('YES')
            break
        else:
            print('NO')
            break
        