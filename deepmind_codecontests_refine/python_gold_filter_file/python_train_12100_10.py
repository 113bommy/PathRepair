# -*- coding: utf-8 -*-
"""
Created on Fri Apr  3 14:15:46 2020

@author: USER
"""
def solve(l):
    for i in range(l):
        x,y,a,b=map(int,input().split())
        ll=(y-x)%(b+a)
        if ll:
            print(-1)
        else:
            print((y-x)//(b+a))
            
            
        
solve(int(input()))