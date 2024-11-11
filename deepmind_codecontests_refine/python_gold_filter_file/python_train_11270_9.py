# -*- coding: utf-8 -*-
"""
Created on Tue Aug 25 20:14:17 2020

@author: RACHIT
"""

if __name__=="__main__":
    t=int(input())
    while(t):
        n=int(input())
        x=[int(i) for i in input().split()]
        lol=False
        for i in range(1,len(x)-1):
            if x[i-1]<x[i] and x[i]>x[i+1]:
                print("YES")
                print(i,i+1,i+2)
                lol=True
                break
        if not lol:
            print("NO")
        t-=1