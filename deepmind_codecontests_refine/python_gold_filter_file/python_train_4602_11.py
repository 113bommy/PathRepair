# -*- coding: utf-8 -*-
"""
Created on Tue Oct 22 22:15:12 2019

@author: vishal
"""

T=int(input())
while T:
    N=int(input())
    P=list(map(float,input().split()))
    M=int(input())
    Q=list(map(float,input().split()))
    num=0
    odd=0
    even=0
    for i in P:
        if i==int(i):
            if i%2==0:
                even+=1
            else:
                odd+=1
        
    for j in Q:
        if j==int(j):
            if j%2==0:
                num+=even
            else:
                num+=odd
            
    print(num)
    T-=1
                