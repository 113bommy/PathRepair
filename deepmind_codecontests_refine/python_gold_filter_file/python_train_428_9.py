#!/usr/bin/env python

for _ in range(int(input())):
	n, s = int(input()), input()

	print(0 if (s[0] == '>' or s[-1] == '<') else min(s.index('>'), s[::-1].index('<')))
