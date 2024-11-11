#!/usr/bin/env python3
# -*- coding: utf-8 -*-


n = int(input())
a = input()





s = 0
for i,j in enumerate(a):
     if int(j)%2 ==0:
         s += i + 1
print(s)         