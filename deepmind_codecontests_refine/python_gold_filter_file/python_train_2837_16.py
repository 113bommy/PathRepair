# -*- coding: utf-8 -*-
"""
Created on Mon Jul 27 06:40:01 2020

@author: Tanmay
"""

for _ in range(int(input())):
 ans=[]
 col=[]
 row=[]
 n,m=map(int,input().strip().split())
 for i in range(n):
    arr=list(map(int,input().split()))
    for j in range(len(arr)):
        if(arr[j]==1):
            col.append(j)
            row.append(i)
    ans.append(arr)        
 
 new_m=[]
 uc=0
 for i in range(n):
     b=[]
     for j in range(m):
         if(i in row or j in col):
             continue
         else:
             uc+=1
             col.append(j)
             row.append(i)
 if(uc%2==0):
     print('Vivek')
 else:
     print('Ashish')