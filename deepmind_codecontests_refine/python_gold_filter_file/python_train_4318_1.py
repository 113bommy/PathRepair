#!/usr/bin/env python3

x, y = map(int, input().split())
u, v = map(int, input().split())
n = int(input())
s = 0
for i in range(n):
    a, b, c = map(int, input().split())
    s += (a * x + b * y + c > 0) ^ (a * u + b * v + c > 0)
print(s)
