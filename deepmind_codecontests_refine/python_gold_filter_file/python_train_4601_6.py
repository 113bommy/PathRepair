import sys, os
# import numpy as np
from math import sqrt, gcd, ceil, log, floor
from bisect import bisect, bisect_left
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop
from itertools import permutations
input = sys.stdin.readline
read = lambda: list(map(int, input().strip().split()))
# read_f = lambda file:  list(map(int, file.readline().strip().split()))
# from time import time
# sys.setrecursionlimit(5*10**6)

MOD = 10**9 + 7

def f(n, arr):
	m = len(n)
	dp = [[[0]*(10) for j in range(2)] for i in range(m)]

	# for j in range(2):
	# 	if j:
	# 		for p in range(int(n[m-1])+1):
	# 			dp[-1][j][p%k] += 1
	# 	else:
	# 		for p in range(10):
	# 			dp[-1][j][p%k] += 1

	ans = int(n)
	for i in range(m-1, -1, -1):
		for j in range(2):
			for p in range([10, int(n[i])+1][j]):
				# for o in range(k):
				# 	dp[i][j][(p+o)%k] += dp[i+1][p == int(n[i]) and j][o]
				# 	dp[i][j][(p+o)%k] %= MOD
				# print(i, j , p == int(n[i]) and j, p)
				# print(i, j, p, i+1 , m,[0, 1][i+1 <= m-1])
				dp[i][j][p] += 1+(dp[i+1][(p == int(n[i])) and  j][p] if i+1 <= m-1 else 1)
				f = 0
				for k in range(10):
					if dp[i][j][k] == arr[k]:f |= 1
				ans -= f
			for x in dp:
				for y in range(2):
					print(y,  x[y])


	return(ans)

def main():
	# file1 = open("C:\\Users\\shank\\Desktop\\Comp_Code\\input.txt", "r")
	# n = int(file1.readline().strip()); 
	# arr = list(map(int, file1.read().strip().split(" ")))
	# file1.close()
	# n = int(input())

	for _ in range(int(input())):
		n = int(input()); a, b = [], []
		dp = [[10**18 + 1]*3 for i in range(n)]
		la, lb = read()
		for i in range(3):dp[0][i] = lb * i

		for i in range(1, n):
			a, b = read()
			for j in range(3):
				t = a+j
				for k in range(3):
					if t == la+k:
						dp[i][j] = j*b + min(dp[i-1][(k+1)%3], dp[i-1][(k+2)%3])
					else:
						dp[i][j] = min(dp[i][j], j*b + dp[i-1][k])

			la, lb = a, b
		# for i in dp:
		# 	print(i)
		print(min(dp[n-1]))

	

	# file = open("output.txt", "w")
	# file.write(ans+"\n")
	# file.close()

if __name__ == "__main__":
	main()

"""
4 1 2 5 1
2 2 3 4 5

2 3 
"""