#!/usr/bin/python3

import math

def nCr(n, r):
	a = 1
	for i in range(n-r+1, n+1):
		a *= i
	return a//math.factorial(r)

n = int(input())

ans = nCr(n, 7) + nCr(n, 6) + nCr(n, 5)
print(str(ans))

