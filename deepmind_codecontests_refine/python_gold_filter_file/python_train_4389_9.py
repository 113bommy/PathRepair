#!/usr/bin/env python
from itertools import accumulate

n, s, t = int(input()), input(), input()

a = [0,] + [ord(s[i]) + ord(t[i]) - (ord('a') << 1) for i in range(n)]

for i in range(n, -1, -1):
	if a[i] >= 26:
		a[i] -= 26
		a[i - 1] += 1

for i in range(n, -1, -1):
	if a[i] & 1:
		a[i + 1] += 13
	a[i] >>= 1

print(''.join(map(lambda _: chr(ord('a') + _), a[1:])))
