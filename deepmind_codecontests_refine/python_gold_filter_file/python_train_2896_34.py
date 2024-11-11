#!/usr/bin/env python3
import sys
input = sys.stdin.readline

n, k = map(int, input().split())
a = [int(item) for item in input().split()]
cuma = [0]
for item in a:
    cuma.append(cuma[-1] + item)
b = []
for i in range(n):
    for j in range(i + 1, n+1):
        b.append(cuma[j] - cuma[i])
ans = 0
for i in range(41, -1, -1):
    subset = []
    for item in b:
        if item & 1 << i: 
            subset.append(item)
    if len(subset) >= k:
        ans |= 1 << i
        b = subset[:]
print(ans)