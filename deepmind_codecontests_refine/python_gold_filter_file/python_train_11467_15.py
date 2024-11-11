import io, sys, atexit, os

import math as ma
from sys import exit
from decimal import Decimal as dec
from itertools import permutations


def li ():
	return list (map (int, input ().split ()))


def num ():
	return map (int, input ().split ())


def nu ():
	return int (input ())


def find_gcd ( x, y ):
	while (y):
		x, y = y, x % y
	return x


def solve ():
	t = 1
	for it in range (t):
		n,m = num ()
		a = li ()
		a.sort(reverse = True)
		lo=1
		hi=n
		ans=-1
		while(lo<=hi):
			mid=(lo+hi)//2
			pp=0
			ss=0
			for i in range(n):
				if (i % mid == 0 and i != 0):
					pp += 1
				ss+=max(a[i]-pp,0)
			if(ss>=m):
				hi=mid-1
			else:
				lo=mid+1
		if(lo==n+1):
			print(-1)
		else:
			print(lo)


if __name__ == "__main__":
	solve ()