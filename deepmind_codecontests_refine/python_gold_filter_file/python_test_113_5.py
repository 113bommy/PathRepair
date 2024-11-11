# your code goes here
# your code goes here
import sys
import math
from fractions import Fraction
from decimal import *
input = sys.stdin.readline


t = int(input())
while t>0:

	inp = input().strip()
	arr = [int(x) for x in inp.split(' ')]
	x1 = arr[0]
	p1 = arr[1]

	inp = input().strip()
	arr = [int(x) for x in inp.split(' ')]
	x2 = arr[0]
	p2 = arr[1]

	x = x1
	d1 = p1
	while x>0:
		d1 += 1
		x=x//10

	x = x2
	d2 = p2
	while x>0:
		d2 += 1
		x=x//10
	
	if d1 > d2:
		print('>')
	elif d1 < d2:
		print('<')
	else:
		s1 = str(x1)
		s2 = str(x2)


		i = 0
		printed = False
		while i<len(s1) and i<len(s2):
			if s1[i] > s2[i]:
				print('>')
				printed = True
				break
			elif s1[i] < s2[i]:
				print('<')
				printed = True
				break
			i += 1
		if not printed:
			if i<len(s1):
				while i<len(s1):
					if s1[i] != '0':
						print('>')
						printed = True
						break
					i += 1
				if not printed:
					print('=')
			elif i<len(s2):
				while i<len(s2):
					if s2[i] != '0':
						print('<')
						printed = True
						break
					i += 1
				if not printed:
					print('=')
			else:
				print('=')
	
	t -= 1
