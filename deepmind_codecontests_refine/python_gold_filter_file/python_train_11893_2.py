# -*- coding: utf-8 -*-
"""
Created on Wed Jun 17 13:44:39 2020

@author: Mridul Garg
"""

#o = int(input())
#for _ in range(o):
k = int(input())

def high(a):
    ans = 1
    a >>= 1
    while a != 0:
        a >>= 1
        ans *= 2
    
    return ans

if k == 0:
    print(1, 1)
    print(1)
else:
    
    
    t = high(k) 
    t = t<<1
    a = t + k
    a1 = t
#    print(a)
    
    A = [[0 for i in range(4)]for i in range(3)]
    for i in range(3):
        A[0][i] = k
    for i in range(3):
        A[i][0] = a1
    
    for i in range(3):
        A[-1][i] = a1
    
    for i in range(3):
        A[i][-2] = k
    
    A[0][0] = a
    A[-1][-1] = k
    A[-1][-2] = a
    
    print(3, 4)
    for i in A:
        for j in i:
            print(j, end = " ")
        print()
