
import sys
from collections import deque, defaultdict
import copy
import bisect
sys.setrecursionlimit(10 ** 9)
import math
import heapq
from itertools import product, permutations,combinations
import fractions

import sys
def input():
	return sys.stdin.readline().strip()

N, Q = list(map(int, input().split()))
A = list(map(int, input().split()))

sum_list = [0]
even_odd_sum = [0, 0]
for i in range(N):
	sum_list.append(sum_list[-1] + A[i])
	even_odd_sum.append(even_odd_sum[-2] + A[i])

for q in range(Q):
	x = int(input())
	if x >= A[-1]:
		print(even_odd_sum[-1])
	else:
		loc_min = bisect.bisect_left(A, x)
		loc_min = max(loc_min, N // 2)
		loc_max = (loc_min + N) // 2

		t = (loc_min + loc_max) // 2


		#print(x, loc_min, loc_max, t, 2*t - N - 1)
		while (loc_min <= loc_max):

			if 2*t - N - 1 >= 0 and A[t - 1] - x >= x - A[2*t - N - 1]:
				loc_max = t - 1
			elif 2*t - N >= 0 and A[t] - x < x - A[2*t - N]:
				loc_min = t + 1
			elif 2*t - N < 0 and A[t] - x < x - A[0]:
				loc_min = t + 1
			else:
				break

			t = (loc_min + loc_max) // 2
		ans = sum_list[-1] - sum_list[t] + even_odd_sum[2*t - N - 1 + 2]
		print(ans)