# -*- coding: utf-8 -*-
"""
Created on Tue Dec 15 16:48:39 2020

@author: lenovo
"""


def fake(string):
    value='heidi'
    i=0
    j=0
    while i<len(string) and j<len(value):
        if string[i]==value[j]:
            i=i+1
            j=j+1
        else:
            i=i+1
    return j==len(value)
string=input()
if fake(string):
    print('YES')
else:
    print('NO')
            