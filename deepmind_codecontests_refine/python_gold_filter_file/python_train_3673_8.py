import sys, os
from math import sqrt, gcd, ceil, log, floor
from bisect import bisect, bisect_left
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop
input = sys.stdin.readline
read = lambda: list(map(int, input().strip().split()))
# read_f = lambda file:  list(map(int, file.readline().strip().split()))

# from time import time

# sys.setrecursionlimit(10**6)

MOD = 998244353



def main():
	# file1 = open("C:\\Users\\shank\\Desktop\\Comp_Code\\input.txt", "r")
	# n = int(file1.readline().strip()); 
	# arr = list(map(int, file1.read().strip().split(" ")))
	# file1.close()
	ans_ = []
	for _ in range(int(input())):
		n =int(input()); s = input()

		a = s.count(">"); b = s.count("<")
		if a == 0 or b == 0:ans_.append(str(n))
		else:
			sett = set()
			for i in range(n):
				if s[i] == "-":
					sett.add(i%n)
					sett.add((i+1)%n)
			ans_.append(str(len(sett)))
	print("\n".join(ans_))


	# file = open("output.txt", "w")
	# file.write(ans+"\n")
	# file.close()

if __name__ == "__main__":
	main()








"""
K = 

0 1 2 3 4 ... x1

0 1 2 3 4 5 6 ... x2

1 = [0,1,2,3,..,x1]
2 = [i+dp[1][k-i]]
3 = [i+d[2][k-i]]






3 4 
1 2 3

0 1 3
0 2 2
1 0 3
1 1 2
1 2 1
"""