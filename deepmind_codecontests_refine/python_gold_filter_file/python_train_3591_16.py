from sys import stdin
import math

n, m = map(int, stdin.readline().split())

k = n - m
if n == 1:
    print (1)
elif m <= k:
    print(m + 1)
else:
    print(m - 1)