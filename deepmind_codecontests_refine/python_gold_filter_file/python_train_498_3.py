#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#

"""
tenka1-2018 E
"""

from itertools import product
from itertools import combinations

h, w = map(int, input().split())
slili = [list(input()) for i in range(h)]

coinsetli = [set() for i in range(h+w)]
for i, j in product(range(h), range(w)):
    if slili[i][j] == '#':
        coinsetli[i+j+1].add(j-i)

jmin = -304
jmin2 = jmin+2


coinacumdictli = [[] for i in range(h+w)]
for i in range(1, h+w):
    tmp = 0
    tt = (i % 2) - 1
    for j in range(jmin+tt, 303, 2):
        if j in coinsetli[i]:
            tmp += 1
        coinacumdictli[i].append(tmp)


coinacumdictli2 = [[] for i in range(h+w)]
for i in range(1, h+w):
    tt = (i % 2) - 1
    for j in range(len(coinacumdictli[i])-1):
        coinacumdictli2[i].append(coinacumdictli[i][j]+coinacumdictli[i][j+1])


coinlili = [[] for i in range(len(coinsetli))]
for i in range(len(coinsetli)):
    tt = (i % 2) - 1

    def rescale(x):
        return (x-jmin2-tt)//2
    coinlili[i] = sorted(list(map(rescale, coinsetli[i])))


ansdouble = 0
for i in range(1, h+w):
    tt = (i % 2) - 1
    for x, y in combinations(coinlili[i], 2):
        j = 2*(y-x)
        imj = i-j
        ipj = i+j
        if imj >= 1:
            ansdouble += coinacumdictli2[imj][y] - coinacumdictli2[imj][x]
        if ipj <= h+w-1:
            ansdouble += coinacumdictli2[ipj][y] - coinacumdictli2[ipj][x]

# repeat after reversing along the vertical axis
for i in range(h):
    slili[i].reverse()

coinsetli = [set() for i in range(h+w)]
for i, j in product(range(h), range(w)):
    if slili[i][j] == '#':
        coinsetli[i+j+1].add(j-i)

jmin = -304
jmin2 = jmin+2

coinacumdictli = [[] for i in range(h+w)]
for i in range(1, h+w):
    tmp = 0
    tt = (i % 2) - 1
    for j in range(jmin+tt, 303, 2):
        if j in coinsetli[i]:
            tmp += 1
        coinacumdictli[i].append(tmp)


coinacumdictli2 = [[] for i in range(h+w)]
for i in range(1, h+w):
    tt = (i % 2) - 1
    for j in range(len(coinacumdictli[i])-1):
        coinacumdictli2[i].append(coinacumdictli[i][j]+coinacumdictli[i][j+1])

coinlili = [[] for i in range(len(coinsetli))]
for i in range(len(coinsetli)):
    tt = (i % 2) - 1

    def rescale(x):
        return (x-jmin2-tt)//2
    coinlili[i] = sorted(list(map(rescale, coinsetli[i])))


for i in range(1, h+w):
    tt = (i % 2) - 1
    for x, y in combinations(coinlili[i], 2):
        j = 2*(y-x)
        imj = i-j
        ipj = i+j
        if imj >= 1:
            ansdouble += coinacumdictli2[imj][y] - coinacumdictli2[imj][x]
        if ipj <= h+w-1:
            ansdouble += coinacumdictli2[ipj][y] - coinacumdictli2[ipj][x]

print(ansdouble//2)
