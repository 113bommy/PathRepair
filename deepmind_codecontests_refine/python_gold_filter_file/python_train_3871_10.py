# kartikay26

from math import *
from collections import *
from itertools import *
from functools import *
from random import *
def getl(t=int): return [t(x) for x in input().split()]
def get(t=int): return t(input())
alphabet = [chr(x) for x in range(ord('a'), ord('z')+1)]
alnum = lambda x: ord(x) - ord('a')

def main():
	n, k = getl()
	a = getl()
	a.sort()
	# print(a)
	i = n // 2 # middle
	z = 1
	while i < n-1 and k >= 0:
		# print("dbg",i,k)
		k_old = k
		k -= (a[i+1] - a[i]) * z
		if k < 0:
			print(a[i] + (k_old // z))
			return
		else:
			i += 1
		z += 1
	# print("dbg",i,k)
	print(a[n-1] + k // (n // 2 + 1))

if __name__ == "__main__":
	main()
