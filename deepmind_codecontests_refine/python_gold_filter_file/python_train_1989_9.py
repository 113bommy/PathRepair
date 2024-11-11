import math

n = int(input())
m = int(input())
ns = sorted([int(input()) for _ in range(n)])
mx = ns[-1]
b = ns[-1] + m
s = sum(ns)
t = mx * n
m -= t - s
if m > 0:
    a = math.ceil(m / n) + mx
else:
    a = mx
print(a, b)