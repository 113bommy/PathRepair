from collections import defaultdict
import heapq

n = int(input())
arr =[input() for _ in range(n)]

graph = defaultdict(list)
in_degree = defaultdict(int)
flag = True

for i in range(1, n):
	cur, prev = arr[i], arr[i-1]

	for j in range(min(len(cur), len(prev))):
		if cur[j] != prev[j]:
			graph[prev[j]].append(cur[j])
			in_degree[cur[j]] += 1
			break
	else:
		if len(prev) > len(cur):
			flag = False

def bfs(graph, in_degree):
	pq = []
	vis_set = set()
	vis_count = 0
	T = []
	for i in range(26):
		# print(chr(ord('a')+i), in_degree[chr(ord('a')+i)])
		if in_degree[chr(ord('a')+i)]==0:
			in_degree[chr(ord('a')+i)] = 0
			heapq.heappush(pq, chr(ord('a')+i))
			vis_set.add(chr(ord('a')+i))
			vis_count += 1

	while pq:
		vert = heapq.heappop(pq)
		T.append(vert)
		for other_vert in graph[vert]:
			if not other_vert in vis_set:
				in_degree[other_vert] -= 1
				if in_degree[other_vert] == 0:
					heapq.heappush(pq, other_vert)
					vis_set.add(other_vert)
					vis_count += 1
	if vis_count != 26:
		return []
	return T
if flag:
	ans = bfs(graph, in_degree)
	print(''.join(ans) if ans else "Impossible")
else:
	print("Impossible")