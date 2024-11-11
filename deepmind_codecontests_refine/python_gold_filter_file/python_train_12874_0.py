# -*- coding: utf-8 -*-

from math import *

n = input()
a = input().split()
b = set()
for i in a:
    if i != '0':
        b.add(i)
print(len(b))