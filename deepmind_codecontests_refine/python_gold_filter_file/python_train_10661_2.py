from sys import stdin, stdout
import math
from itertools import permutations, combinations
from collections import defaultdict
from bisect import bisect_left


mod = 1000000007

def L():
	return list(map(int, stdin.readline().split()))

def In():
	return map(int, stdin.readline().split())

def I():
	return int(stdin.readline())

def printIn(ob):
	return stdout.write(str(ob)+'\n')

def powerLL(n, p):
	result = 1
	while (p):
		if (p&1):
			result = result * n % mod
		p = int(p / 2)
		n = n * n % mod
	return result

#--------------------------------------
import sys
def myCode():
	n,k = In()
	k = n-k
	if k == 0:
		print(-1)
	else:
		print(k, end=' ')
		for i in range(1, k):
			print(i, end=' ')
		for i in range(k + 1, n + 1):
			print(i, end=' ')
def main():
    # for t in range(I()):
	    myCode()
if __name__ == '__main__':
    # print(math.sqrt(4))
    main()