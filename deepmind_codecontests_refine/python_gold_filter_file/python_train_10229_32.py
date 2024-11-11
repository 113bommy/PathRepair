# -*- coding: utf-8 -*-
"""
Created on Thu Jun 11 19:37:41 2020

@author: Mongia Bros
"""

for _ in range(int(input())):

    a,b,n = list(map(int,input().split()))
    if a>b:
        a,b = b,a #making a always larger
    c=0
    k=0
    while a<=n and b<=n:
        a = a+b
        c = c+1
        if a>n:
            print(c+k)
            break
        
        b = b+a
        k=k+1
        if b>n:
            print(c+k)
            break