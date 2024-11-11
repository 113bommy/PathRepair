#!/usr/bin/env python3 
import re
n = int(input())

stars = n // 2
line = n * 'D'
mines = []
for i in range(1, len(line) // 2 + 1):
	mines.insert(0, ((i * '*') + line[i:len(line) - i] + (i * '*')))

for i in range(len(mines)):
	print(mines[i])

print(line)

for i in range(len(mines) - 1, -1, -1):
	print(mines[i])