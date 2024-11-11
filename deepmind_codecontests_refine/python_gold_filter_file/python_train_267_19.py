# -*- coding: utf-8 -*-
"""
Created on Wed Apr  1 01:15:16 2020

@author: alexi
"""



#https://codeforces.com/problemset/problem/820/A --- Alexis Galvan


def book_reading():
    time = list(map(int, input().split()))
    
    if time[0] <= time[1]:
        return 1
    elif time[0] == 1:
        return 1
        
    output = time[1]
    counter = 1
    mult = 1
    while True:
        output -= time[4]
        add = time[1] + (time[3]*mult)
        if (add) > time[2]:
            output += time[2]
        else:
            output += add
        counter += 1
        mult += 1
        if output >= time[0]:
            return counter


A = book_reading()
print(A)            
        
    
    
    


    
    
    