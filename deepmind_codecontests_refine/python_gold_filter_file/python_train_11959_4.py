#!/usr/bin/env python
# -*- coding: utf-8 -*-

while True:
    n = int(input())
    if n == 0:
        break
    a = []
    for i in range(0,n):
        a.append(int(input()))
    sumMax = -100000
    for i in range(0,n):
        tmp = 0
        for j in range(i,n):
            tmp += a[j]
            sumMax = max(sumMax,tmp)
    print(sumMax)