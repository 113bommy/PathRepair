#!/usr/bin/env python3
import sys

from math import gcd
def rint():
    return map(int, sys.stdin.readline().split())
#lines = stdin.readlines()

"x: sword num of each type"
"y: people"
"z: taken sword num"
"ai: remained sword num"
"find min y"
n = int(input())
a = list(rint())

b = []
amax = max(a)
for i in range(n):
    b.append(amax-a[i])

g = 0
for i in range(n):
    g = gcd(g, b[i])
y = 0
for i in range(n):
    y += b[i]//g

print(y, g)

