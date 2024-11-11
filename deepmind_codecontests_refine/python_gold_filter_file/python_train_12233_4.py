#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input())

for i in range(2,10**6 + 1)[::-1]:
    while n % (i*i) == 0:
        n = n//i
print(n)
