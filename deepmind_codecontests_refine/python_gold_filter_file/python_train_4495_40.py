# -*- coding: utf-8 -*-
"""
Created on Wed Oct 21 15:16:37 2020

@author: 17831
"""

str = input()
word = str.lower()
output = []
vowel = ['a','e','i','o','u','y']

for char in word:
    if char not in vowel:
        output.append('.')
        output.append(char)
    
print(''.join(output))