#!/usr/bin/env python3
import sys

def rint():
    return map(int, sys.stdin.readline().split())
#lines = stdin.readlines()

n = int(input())

s = list(input())
d = -1
for i in range(0, n-1):
    if s[i] > s[i+1]:
        d = i
        break
else:
    d = n-1

if d == n-1:
    ss = s[:d]
else:
    ss = s[:d] + s[d+1:]
print("".join(ss))


