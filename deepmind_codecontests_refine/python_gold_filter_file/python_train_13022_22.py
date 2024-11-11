# -*- coding: utf-8 -*-
"""
Created on Fri Aug  3 01:50:46 2018

@author: Miha
"""

infos = input()
info = infos.split()
n = int(info[0])
m = int(info[1])

full = [i for i in range(1, m+ 1)]

for i in range(n):
    segs = input()
    seg = segs.split()
    seg1 = int(seg[0])
    seg2 = int(seg[1])
    
    for j in range(seg1, seg2 + 1):
        if j in full:
            full.remove(j)
L = len(full)

print(L)

if L != 0:
    full = map(str, full)
    print(' '.join(full))
    