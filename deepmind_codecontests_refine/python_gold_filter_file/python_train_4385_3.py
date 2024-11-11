# -*- coding: utf-8 -*-
"""
Created on Fri Nov 20 16:21:09 2020

@author: user
Link :https://codeforces.com/problemset/problem/1054/A
"""

x , y, z, t1,t2, t3 = map(int,input().split())
# t1 /=2
# t2 /=2
eslelevator = abs(x-z)*t2 + abs(x-y)*t2 + 3*t3
stair = abs(x-y)*t1
if  eslelevator <= stair :
    print("YES")
else :
    print("NO")