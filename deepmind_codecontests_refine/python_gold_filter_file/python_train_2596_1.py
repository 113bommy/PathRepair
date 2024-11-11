#!/usr/bin/env python
# -*- coding: utf-8 -*-

from math import sqrt

while True:
    e = int(input())
    if e == 0:
        break
    ans = 10**9
    for z in range(e):
        if z**3 > e:
            break
        y = int(sqrt(e-z**3))
        x = e - y ** 2 - z ** 3
        ans = min(ans,x+y+z)
    print(ans)