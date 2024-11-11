# -*- coding: utf-8 -*-
"""
Created on Sat May 29 09:20:52 2021

@author: TSSPDCL
"""

n=int(input())
right=0
left=0
for i in range(n):
    x,y=map(int,input().split())
    if (x>=0 and y>=0) or (x>=0 and y<=0):
        right+=1
    else:
        left+=1
if right>=left and left==1:
    print("Yes")
elif left>=right and right==1:
    print("Yes")
elif left==0 or right==0:
    print("Yes")
else:
    print("No")