#!/usr/bin/python3

t = 0
r, g, b = map(int, input().split())

while r + g + b > 0:
    r -= min(r, 2)
    t += 1
    r, g, b = g, b, r

print(t + 29)
