# -*- coding: utf-8 -*-
"""
Created on Thu Jan  2 22:46:56 2020

@author: Anukool Dwivedi
"""

n=int(input())
for i in range(n):
    str1,str2=map(str,input().split())
    lst1=list(str1)
    lstord=[]
    for i in range(len(lst1)):
        min1=ord(lst1[i])
        pos=i
        for j in range(len(lst1)-1,i,-1):
            if min1>ord(lst1[j]):
                min1=ord(lst1[j])
                pos=j
        if pos!=i:
            temp=lst1[pos]
            lst1[pos]=lst1[i]
            lst1[i]=temp
            break
        
    str1=''.join(lst1)
    if str1<str2:
        print(str1)
    else:
        print("---")
                