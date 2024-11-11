# -*- coding: utf-8 -*-
"""
@author: zzf
@file: main.py
@time: 2018/11/13
"""
import math

def find(n):
    res = []
    for i in range(1, math.floor(math.sqrt(n)) + 1):
        if n % i == 0:
            res.append(i)
            if n // i != i:
                res.append(n // i)
    return res

n = int(input())

l = find(n)
res = []

for i in range(len(l)):
    k = (n-1)//l[i]+1
    res.append(k + (k-1)*k//2*l[i])
res = sorted(res)

print(" ".join([str(i) for i in res]))















