from sys import stdin,stdout,setrecursionlimit
stdin.readline
def mp(): return list(map(int, stdin.readline().strip().split()))
def it():return int(stdin.readline().strip())
from collections import defaultdict as dd,Counter as C,deque
from math import ceil,gcd,sqrt,factorial,log2,floor
from bisect import bisect_right as br,bisect_left as bl
from heapq import *
mod = 10**9+7
inf = (1<<60)

for _ in range(it()):
	x,n = mp()
	# print(n%4)
	if x&1:
		if n%4 == 0:
			print(x)
		elif n%4 == 2:
			print(x-1)
		elif n%4 == 1:
			print((n//4)*4 +x+1)
		else:
			print(-((n//4)*4) +x-4)
	else:
		# print(n%4)
		if n%4 == 0:
			print(x)
		elif n%4 == 2:
			print(x+1)
		elif n%4 == 1:
			print(-((n//4)*4) +x-1)
		else:
			print(((n//4)*4) + x+4)
