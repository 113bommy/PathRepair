#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue May 29 21:10:19 2018

@st0rmbring3r
"""
# l = [int(x) for x in input().split()]
# for _ in range(int(input()))

import math

x,y = [int(x) for x in input().split()]

k1 = math.log(y)*x
k2 = math.log(x)*y

if k1>k2:
    print("<")
elif k1<k2:
    print(">")
else:
    print("=")