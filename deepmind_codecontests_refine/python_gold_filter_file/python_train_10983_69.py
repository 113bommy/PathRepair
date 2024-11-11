#!/usr/bin/python3

s = input()
low = sum(1 for c in s if c>'Z')
up = sum(1 for c in s if c<'a')

if up > low:
    print(s.upper())
else:
    print(s.lower())

