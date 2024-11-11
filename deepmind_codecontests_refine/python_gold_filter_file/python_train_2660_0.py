# -*- coding: utf-8 -*-
"""
Created on Tue Jan  7 18:25:28 2020

@author: PC
"""

def triangle(a, b, c, d):
   
    Arr1 = [a, b, c]
    Arr1.sort()
    Arr2 = [a, b, d]
    Arr2.sort()
    Arr3 = [a, c, d]
    Arr3.sort()
    Arr4 = [d, b, c]
    Arr4.sort()
    
    if (Arr1[0] + Arr1[1] < Arr1[2]) and (Arr2[0] + Arr2[1] < Arr2[2]) and (Arr3[0] + Arr3[1] < Arr3[2]) and( Arr4[0] + Arr4[1] < Arr4[2]):
        return "IMPOSSIBLE"
    elif (Arr1[0] + Arr1[1] > Arr1[2]) or (Arr2[0] + Arr2[1] > Arr2[2]) or (Arr3[0] + Arr3[1] > Arr3[2]) or (Arr4[0] + Arr4[1] > Arr4[2]):
        return "TRIANGLE"
    return "SEGMENT"

arr = list(map(int, input().split())) 
print(triangle(arr[0], arr[1], arr[2], arr[3]))
    