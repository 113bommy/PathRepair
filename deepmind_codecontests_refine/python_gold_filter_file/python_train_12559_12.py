# -*- coding: utf-8 -*-
"""
Created on Sat Feb  3 16:11:46 2018

@author: hp
"""




n=int(input())
for i in range(0,n):
    students=int(input())
    tab=[0]*students
    k=0
    for j in range(1,students+1):
        inn=input().split()
        
        innInt=[int(x) for x in inn]
        
        
        if(k<=innInt[1]):
            #tab[j]=[innInt[0],innInt[1]]
            if(k<innInt[0]):k=innInt[0]
            tab[j-1]=str(k)
           # print(str(k),end="")
            k=k+1
        else: 
            tab[j-1]="0"
            #print(0,end="")
    for pff in range(0,len(tab)-1):
        print(tab[pff],end=" ")
    print(tab[-1])
        
    