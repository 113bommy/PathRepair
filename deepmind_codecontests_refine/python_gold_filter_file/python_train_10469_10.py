# -*- coding: utf-8 -*-
"""
Created on Fri Oct 16 07:49:23 2020

@author: HP
"""


a="abcdefghijklmnopqrstuvwxyz"
letter = input()
move=0
for i in letter:
    
    clock=a.index(i)
    antiClock= 26-a.index(i)
    ad=clock
    if clock>antiClock:
        ad=antiClock
    move=move+ad
    a=a[a.index(i):len(a)]+a[0:a.index(i)]
print(move)