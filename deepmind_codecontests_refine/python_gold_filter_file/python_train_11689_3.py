# -*- coding: utf-8 -*-
"""
Created on Fri Oct  2 15:16:45 2020

@author: Dark Soul
"""


n=int(input(''))
a=list(map(int,input().split()))
b=list(map(int,input().split()))
 
mxsol=min(a[0],b[1])+min(a[1],b[2])+min(a[2],b[0])
mnsol=max(a[0]-b[0]-b[2],a[1]-b[1]-b[0],a[2]-b[2]-b[1],0)

 
 
 
print(mnsol,mxsol)