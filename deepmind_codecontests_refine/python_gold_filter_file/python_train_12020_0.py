# -*- coding: utf-8 -*-
"""
Created on Thu Dec 10 14:49:38 2020

"""
n, m, a, b = map(int, input().split())

if b/m < a:
    tickets = int( (n - n%m)/m)
    if (n-tickets*m)*a < b:
        print(b*tickets +(n-tickets*m)*a)
    else:
        print(b*(1+tickets))
else:
    print(a*n)