# -*- coding: utf-8 -*-
"""
Created on Thu Nov  8 21:05:18 2018

@author: japesh
"""

n,m=map(int,input().split())
res=list(map(int,input().split()))
taxi=list(map(int,input().split()))
taxi.append('#')
i,j=0,0
flag=0
temp1,temp2=0,0
while j<len(taxi):
    if m==1:
        print(n, end=' ')
        break
    elif taxi[j]==1:
        if flag==0:
            flag=1
            i=j
            temp1=i
        elif flag==1:
            for k in range(j-i-1):
                comp1=res[i+k+1]-res[i]
                comp2=res[j]-res[i+k+1]
                if comp1<=comp2:
                    temp1+=1
                else:
                    temp2+=1
            print(temp1,end=' ')
            temp1=temp2
            temp2=0
            i=j
    elif taxi[j]=='#':
        print(temp1+j-i-1,end=' ')
        break
        
    j=j+1