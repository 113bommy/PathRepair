
import sys
from collections import deque, defaultdict
import copy
import bisect
#sys.setrecursionlimit(10 ** 9)
import math
import heapq
from itertools import combinations, permutations

import sys
def input():
	return sys.stdin.readline().strip()

N, M = list(map(int, input().split()))

graph = [[] for _ in range(N)]
graph2 = [-1 for _ in range(N)]
for i in range(M):
	a, b = list(map(int, input().split()))
	a -= 1
	b -= 1
	graph[a].append(b)
	graph[b].append(a)

que = deque([])
que.append(0)
graph2[0] = 0
nibu = 1

num01 = dict()
num01[0] = 1
num01[1] = 0

while len(que) > 0:
	node = que.popleft()
	for edge in graph[node]:
		if graph2[edge] == -1:
			graph2[edge] = (graph2[node] + 1) % 2
			que.append(edge)
			num01[graph2[edge]] += 1
		elif graph2[node] == graph2[edge]:
			nibu = 0

if nibu == 0:
	print(N*(N-1)//2 - M)
else:
	print(num01[0]*num01[1] - M)