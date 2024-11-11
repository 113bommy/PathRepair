# -*- coding: utf-8 -*-
"""
Created on Fri Apr  3 15:51:49 2020

@author: prana
"""

n=int(input())
if n%2==0:
    print(int(n/2))
    print((int(n/2)-1)*"2 "+"2")
elif n>3 and n%2!=0:
    print(int(n//2))
    print((int(n//2)-1)*"2 "+"3")
elif n==3:
    print(1)
    print(3)