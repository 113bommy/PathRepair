# -*- coding: utf-8 -*-
"""
Created on Mon Jun  8 10:55:25 2020

@author: Nada Adel
"""

import os
import sys
from atexit import register
from io import BytesIO




n = int(input())
line=''
x={}
y={}
pairs={}
for i in range(n):
    line=input()
    line=line.split()
    if int(line[0]) not in x:
        x[int(line[0])]=1
    else:
        x[int(line[0])]+=1
    
    if int(line[1]) not in y:
        y[int(line[1])]=1
    else:
        y[int(line[1])]+=1
    if (int(line[0]),int(line[1])) not in pairs:
        pairs[(int(line[0]),int(line[1]))]=1
    else:
        pairs[(int(line[0]),int(line[1]))]+=1


sumX=0
sumY=0
sumPairs=0
for key,value in x.items():
    if value!=1:
        sumX+=value*(value-1)/2.0

for key,value in y.items():
    if value!=1:
        sumY+=value*(value-1)/2.0
for key,value in pairs.items():
    if value!=1:
        sumPairs+=value*(value-1)/2.0
print(int(sumX+sumY-sumPairs))
    
    














