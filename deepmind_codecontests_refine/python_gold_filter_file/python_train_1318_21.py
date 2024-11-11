#!/usr/bin/env python3
from sys import stdin, stdout

def rint():
    return map(int, stdin.readline().split())
#lines = stdin.readlines()

s = input()

p = 0
l = 0
for ss in s:
    if ss == 'o':
        p += 1
    else:
        l += 1

if p == 0:
    print("YES")
elif l%p == 0:
    print("YES")
else:
    print("NO")