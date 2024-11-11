# from functools import lru_cache
from sys import stdin, stdout
import sys
from math import *
# from collections import deque
# sys.setrecursionlimit(3*int(1e5))
# input = stdin.buffer.readline
# print = stdout.write
 
# @lru_cache()
for __ in range(int(input())):
	a,b,c=map(int,input().split())
	if(a>=c):
		print(-1,b)
	else:
		if(a*b<=c):
			print(1,-1)
		else:
			print(1,b)



