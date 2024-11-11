#!/usr/bin/env python3

from math import sqrt

def sum_digits(x):
    res = 0
    while x > 0:
        res += (x % 10)
        x //= 10
    return res


n = int(input())
root = int(sqrt(n))


for i in range(max(root - 100, 1), root + 1, 1):
    sd = sum_digits(i)
    if i * i + sd * i - n == 0:
        print(i)
        exit(0)

print('-1')

