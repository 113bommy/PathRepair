from sys import stdin
import math
from collections import deque
from heapq import heapify, heappop, heappush
from bisect import bisect_left, bisect_right
input = stdin.readline


def ceil(m, n):
	val = m // n
	if(m % n != 0):
		return val + 1
	return val


for _ in range(int(input())):
	n, k = map(int, input().split())
	arr = list(map(int, input().split()))
	arr.sort()
	total = sum(arr)
	if(total <= k):
		print(0)
		continue

	differ = total - k
	diff = [0] * n
	for i in range(n - 1, -1, -1):
		diff[i] = arr[i] - arr[0]
		if(i < n - 1):
			diff[i] = diff[i] + diff[i + 1]


	chances = [0] * n
	for i in range(n - 1, 0, -1):
		chances[i] = max(0, ceil((differ - diff[i]), (n - i + 1))) + (n - i)
	chances[0] = differ
	print(min(chances))
