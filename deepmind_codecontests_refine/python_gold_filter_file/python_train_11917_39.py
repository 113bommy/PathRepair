# -*- coding: utf-8 -*-
"""
Created on Sun Nov 29 18:53:31 2020

@author: Naoroj Farhan
"""

n = int(input())

counter = 1
subtractor = 1

while n >0:
    counter +=1
    subtractor +=counter
    n-=subtractor
    
print (counter-1)


# 1+3+6+10+15+21