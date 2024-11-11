# -*- coding: utf-8 -*-
"""
Created on Thu Oct 10 21:41:00 2019

@author: Mridul Garg
"""

n = int(input())
a = list(input())
b = input()

if n == 1:
    if a[0] != b:
        print(1)
    else:
        print(0)
      
else:

    cost = 0
    i = 0
    while i < n - 1:
#        print(i)
        if a[i] == b[i]:
            i += 1
        else:
            if a[i] != a[1+i] and b[i] != b[1+i]:
                a[i], a[i+ 1] = a[i+ 1], a[i]
                cost += 1
                i += 2
            else:
                cost += 1
                i += 1
#    print(i)
    if a[-1] != b[-1]:
        cost += 1
    
    
#    print()           
    print(cost)