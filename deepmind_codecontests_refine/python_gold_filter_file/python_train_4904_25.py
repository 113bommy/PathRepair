import math as ma
import sys
from sys import exit
from decimal import Decimal as dec
from itertools import permutations


def li():
	return list(map(int , input().split()))


# https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
def modInverse(a , m):
	m0 = m
	y = 0
	x = 1
	if (m == 1):
		return 0
	while (a > 1):
		q = a // m
		t = m
		m = a % m
		a = t
		t = y
		y = x - q * y
		x = t
	if (x < 0):
		x = x + m0
	return x


def num():
	return map(int , input().split())


def nu():
	return int(input())


def find_gcd(x , y):
	while (y):
		x , y = y , x % y
	return x

n=nu()
if(n==1 or n==2):
	print("No")
else:
	print("Yes")
	print(n-1,end=" ")
	for i in range(1,n):
		print(i,end=" ")
	print()
	print(1,n)