# -*- coding: utf-8 -*-
"""
Created on Wed Aug 24 13:19:53 2016

@author: Felicia
"""

s = input()
n = len(s)
hea = -1
tai = -1
new = list(s)

for i in range(n):
    if new[i]!='a':
        hea = i
        for j in range(i+1,n):
            if new[j]=='a':
                tai = j-1
                break
        else:
            tai = n-1
        for k in range(hea,tai+1):
            temp = ord(new[k])-1
            new[k] = chr(temp)
        break

if hea ==-1:
    new[n-1] = 'z'
    
news = ''.join(new)
print(news)
