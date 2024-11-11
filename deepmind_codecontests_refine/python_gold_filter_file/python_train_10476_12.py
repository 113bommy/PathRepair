# -*- coding: utf-8 -*-
"""
Created on Wed Oct  9 14:18:53 2019

@author: Mridul Garg
"""

string = list(input())
n = len(string)

count = 0
temp = string[0]
for i in range(n):
    if string[i] == 'Q':
        for j in range(i + 1, n):
            if string[j] == 'A':
                for k in range(j + 1, n):
                    if string[k] == 'Q':
                        count += 1
#                        print(i, j, k)
print(count)