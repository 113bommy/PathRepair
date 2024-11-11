#!/usr/bin python3
# -*- coding: utf-8 -*-

k = int(input())
n = 50
x = k%n
a = k//n
ret = [a + n-x-1]*(n-x) + [a + n]*x
print(n)
print(' '.join(list(map(str,ret))))