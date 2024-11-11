# -*- coding: utf-8 -*-
"""
Created on Sat Oct  1 10:00:04 2016

@author: Felicia
"""

f=input()
t=input()
l=list(t)

if int(l[3])>=6:
    l[3]='0'

if f=='12':
    if int(l[0])>=2:
        if l[1]!='0':
            l[0]='0'
        else:
            l[0]='1'
    elif l[0]=='0' and l[1]=='0':
        l[0]='1'
    elif l[0]=='1' and int(l[1])>=3:
        l[0]='0'

if f=='24':
    if int(l[0])>=3:
        l[0]='0'
    elif l[0]=='2' and int(l[1])>=4:
        l[0]='0'

print(''.join(l))