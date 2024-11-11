#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def lowbit(x):
    return x&(-x)

flag = False
a, b, n = list(map(int, input().split(' ')))
for x in range(-1005, 1005):
    if a * (x ** n) == b:
        print(x)
        flag = True
        break;
if flag == False:
    print("No solution")
