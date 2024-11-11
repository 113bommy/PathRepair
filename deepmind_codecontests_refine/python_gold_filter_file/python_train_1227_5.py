#!/usr/bin/env python3
from math import cos, sin, pi
n, L = map(int, input().split())
t = [int(input()) for _ in range(n)]
ans = [0, 0]
for i in range(n):
    for j in range(i + 1, n):
        k = (n - 1 - j + i) - (j - i - 1)
        ans[0] += cos(pi * (t[i] + t[j]) / L) * k
        ans[1] += sin(pi * (t[i] + t[j]) / L) * k
for i in range(2):
    ans[i] /= n * (n - 1) * (n - 2) / 6
print(*ans, sep=' ')
