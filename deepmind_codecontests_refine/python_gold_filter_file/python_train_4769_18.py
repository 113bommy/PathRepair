
import sys
from collections import deque, defaultdict
import copy
import bisect
input=sys.stdin.readline
#sys.setrecursionlimit(10 ** 9)
import math
import heapq

Q = int(input())
#Q = 100000
q = []
for i in range(Q):
	q.append(list(map(int, input().split())))
	#q.append([1, (i*17) % 10000, i])

a_list = []
a_list2 = []
b_sum = 0
a_sum = 0
a_sum_half = 0
length = 0
for i in range(Q):
	if len(q[i]) == 3:
		if len(a_list2) == 0:
			D = True
		else:
			x = heapq.heappop(a_list2)
			heapq.heappush(a_list2,x)
			D = (x <= q[i][1])
		length += 1
		if length % 2 == 0 and not D:
			a_sum_half += q[i][1]
			heapq.heappush(a_list, -q[i][1])
		elif length % 2 == 0 and D:
			heapq.heappush(a_list2, q[i][1])
			x = heapq.heappop(a_list2)
			heapq.heappush(a_list, -x)
			a_sum_half += x
		elif length % 2 == 1 and not D:
			a_sum_half += q[i][1]
			heapq.heappush(a_list, -q[i][1])
			x = heapq.heappop(a_list)
			a_sum_half += x
			heapq.heappush(a_list2, -x)
		else:
			heapq.heappush(a_list2, q[i][1])
		a_sum += q[i][1]
		b_sum += q[i][2]
	else:
		if length % 2 == 0:
			argmin_x = -heapq.heappop(a_list)
			heapq.heappush(a_list, -argmin_x)
		else:
			argmin_x = heapq.heappop(a_list2)
			heapq.heappush(a_list2, argmin_x)
		min_x = argmin_x*(length//2) - a_sum_half
		min_x += (a_sum - a_sum_half) - (argmin_x*(length - length//2))
		min_x += b_sum
		print("{0} {1}".format(argmin_x, min_x))