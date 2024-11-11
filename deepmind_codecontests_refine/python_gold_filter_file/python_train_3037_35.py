# -*- coding: utf-8 -*-

# Baqir Khan
# Software Engineer (Backend)

from sys import stdin

inp = stdin.readline

n = int(inp())
a = list(map(int, inp().split()))

prefix = [0] * (n + 1)

for i in range(1, n + 1):
    prefix[i] = prefix[i - 1] + a[i - 1]

q = int(inp())
while q:
    q -= 1
    left, right = map(int, inp().split())
    print((prefix[right] - prefix[left - 1])//10)

