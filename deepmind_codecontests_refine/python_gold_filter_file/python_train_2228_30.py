# -*- coding: utf-8 -*-
"""
Created on Sat Nov  9 19:44:00 2019

@author: jk Jin
"""

n, m = [int(x) for x in input().split()]
fList = [int(x) for x in input().split()]
for i in range(1,m):
    for j in range(i-1,-1,-1):
        if fList[j+1]<fList[j]:
            a = fList[j]
            fList[j] = fList[j+1]
            fList[j+1] = a
            #print(fList)
        else:
            break
#print(fList)
ans = fList[m-1] - fList[0]
for i in range(m-n+1):
    if fList[i+n-1]-fList[i] < ans:
        ans = fList[i+n-1]-fList[i]
print(ans)