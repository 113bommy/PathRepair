# -*- coding: utf-8 -*-
"""
Created on Fri Jul 24 06:06:15 2020

@author: Dark Soul
"""
t=int(input(''))
num=[]
for i in range(t):
    num.append(int(input('')))
for i in num:
    digits=[]
    while i:
        digits.append(i%3)
        i=int(i//3)
    digits.append(0)
    lst=-1
    for j in range(len(digits)):
        if digits[j]==2:
            lst=j
    if lst!=-1:
        while digits[lst]:
            lst+=1
        for j in range(lst):
            digits[j]=0
        digits[lst]=1
    ans=0
    m=1
    for j in range(len(digits)):
        ans+=digits[j]*m
        m*=3
    print(ans)
