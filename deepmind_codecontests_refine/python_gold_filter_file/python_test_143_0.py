from sys import stdin
import math
from collections import deque
from heapq import heapify, heappop, heappush
from bisect import bisect_left, bisect_right
input = stdin.readline

def log(n, m):
	res, val = 0, 1
	while(True):
		if(n == val):
			return res
		elif(n > val):
			return res - 1
		res += 1
		val *= m

def ceil(m, n):
	val = m // n
	if(m % n != 0):
		return val + 1
	return val


for _ in range(int(input())):
	n = int(input())
	arr = list(map(int, input().split()))
	carr, canget = [0] * (n + 1), [0] * (n + 1)
	for a in arr:
		carr[a] += 1
	
	if(carr[0] == 0):
		print(0, *([-1] * n))
		continue

	extras, last = [], 0
	for i in range(n + 1):
		if(carr[i] > 1):
			extras.append([i, carr[i] - 1])
		elif(carr[i] == 0):
			if(len(extras) == 0):
				last = i
				break
			else:
				canget[i] = i - extras[-1][0]
				extras[-1][-1] -= 1
				if(extras[-1][-1] == 0):
					extras.pop()
		last = i


	for i in range(1, n + 1):
		canget[i] += canget[i - 1]
	res = [-1] * (n + 1)
	for i in range(n + 1):
		if(i > last):
			continue
		elif(i == 0):
			res[i] = carr[i]
		else:
			res[i] = canget[i - 1] + carr[i]
	print(*res)
			
