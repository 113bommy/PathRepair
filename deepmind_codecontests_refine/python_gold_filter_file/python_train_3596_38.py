# -*- coding: utf-8 -*-
"""
Created on Thu Nov 29 07:00:00 2018

@author: n
"""
x=input().split()
a=[]
initially=int(x[1])
Whave=initially
numberofboys=0
for i in range(int(x[0])):
    newElement=input()
    a.append(newElement)
    if a[i][0]=='+':
        Whave+=int(a[i][1:])
    else:
        if a[i][0]=='-'and Whave-int(a[i][1:])>=0:
            Whave-=int(a[i][1:])
        else:
            numberofboys+=1
print(Whave,numberofboys)

    
    
        
