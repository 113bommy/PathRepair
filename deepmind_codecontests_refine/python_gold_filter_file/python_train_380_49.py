#!/usr/bin/env python3
from sys import stdin, stdout

def rint():
    return map(int, stdin.readline().split())
#lines = stdin.readlines()

n = int(input())

p = list(rint())

p.sort()
#even
s = 0
for i in range(n//2):
    s+= abs((i+1)*2 - p[i])

seven = s

s = 0
for i in range(n//2):
    s+= abs((i)*2+1 - p[i])

sodd = s

print(min(seven, sodd))



