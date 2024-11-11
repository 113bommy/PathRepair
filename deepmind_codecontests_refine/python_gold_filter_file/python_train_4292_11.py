# -*- coding: utf-8 -*-
"""
Created on Tue Feb  4 23:28:21 2020

@author: User
"""


import math
n = int(input())
num = []
for i in range(n):
    num.append(int(input()))
    
for x in num:
     flag = 0
     counter = 0
     y = int(math.sqrt(x))
    
     for j in range(2,y+1) :
        if flag == 1 : break
        elif x % j == 0 :
                a = int(j)
                nu = int(x/j)
                z=int(math.sqrt(nu))
            
                for k in range(j+1,z+1) :
                    if nu % k == 0 :
                        b = int(k)
                        c = int(nu/k)
                        if b==c or a==c : 
                            counter = 0
                        else :
                            print('YES')
                            print(a,b,c)
                            flag = 1
                            counter = 1
                            break
     if counter == 0 :
        print('NO')


    


    
    
    
    
    
   