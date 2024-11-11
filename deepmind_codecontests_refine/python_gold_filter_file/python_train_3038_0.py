import io, sys, atexit, os
import math as ma
from sys import exit
from decimal import Decimal as dec
from itertools import permutations
from itertools import combinations


def li ():
	return list (map (int, sys.stdin.readline ().split ()))


def num ():
	return map (int, sys.stdin.readline ().split ())


def nu ():
	return int (input ())


def find_gcd ( x, y ):
	while (y):
		x, y = y, x % y
	return x


def lcm ( x, y ):
	gg = find_gcd (x, y)
	return (x * y // gg)


mm = 1000000007

def solve ():
	t = 1
	for tt in range (t):
		n=nu()
		a=[0]*n
		cc=0
		i=0
		j=0
		if(pow(2, int (ma.log2 (n)))==n):
			for i in range (n):
				a [ i ] = [ 0 ] * n
				for j in range (n):
					a [ i ] [ j ] = cc
					cc += 1
			for i in range (n):
				print (*a [ i ])
			continue
		for i in range(n):
			a[i]=[0]*n
		i=0
		j=0
		while(i<n):
			j=0
			while(j<n):
				for k in range(i,i+4):
					for p in range(j,j+4):
						a[k][p]=cc
						cc+=1
				j+=4
			i+=4
		for i in range(n):
			print(*a[i])




if __name__ == "__main__":
	solve ()