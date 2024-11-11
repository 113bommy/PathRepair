# -*- coding: utf-8 -*-
"""
Created on Sat Oct 10 17:44:49 2020

@author: My Family
"""



x=0
X = int(input())
z=[]
for i in range(X):
    a=input()
    z.append(a)
    
    
    
    
    
for j in z:
    if (j=="++X" or j=="X++"):
        x+=1
    elif (j=="--X" or j=="X--"):
        x-=1
        
print(x)