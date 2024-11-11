# -*- coding: utf-8 -*-
"""
Created on Thu Jul 19 10:09:51 2018

@author: User
"""

n, m = map(int, input().split(" "))
summ = 0
for i in range(m) :
    x, d = map(int, input().split(" "))
    summ += x*n
    if d >= 0:
        summ += d*(n-1)*n//2
    else :
        if n % 2 == 0 :
            summ += d*n*n//4
        else :
            summ += d*(n*n-1)//4
print(summ/n)