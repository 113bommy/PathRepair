import sys
from math import sqrt, gcd, ceil, log
# from bisect import bisect, bisect_left
from collections import defaultdict, Counter, deque
# from heapq import heapify, heappush, heappop
input = sys.stdin.readline
read = lambda: list(map(int, input().strip().split()))


def main():
	n, m = read()
	adj = defaultdict(list)
	for i in range(m):
		u, v = read()
		adj[u].append(v)
		adj[v].append(u)
	color = [0]*(n+1)
	stk = []
	visited = [0]*(n+1)
	col = {1:2, 2:1}

	# print(adj, color, visited)
	# for i in range(1, n+1):print(i, color[i])
	for i in range(1, n+1):
		if not visited[i] and adj[i]:
			stk = [i]
			visited[i] = 1
			color[i] = 1
			while stk:
				par = stk.pop()
				for child in adj[par]:
					# print(par, child)
					if color[par] and color[par] == color[child]:
						print(-1); exit()
					if not visited[child]:
						color[child] = col[color[par]]
						visited[child] = 1
						stk.append(child)
	ans = [[], []]
	for i in range(1, n+1):
		if color[i] == 1:
			ans[0].append(i)
		elif color[i] == 2:
			ans[1].append(i)
	print(len(ans[0]))
	print(*ans[0])
	print(len(ans[1]))
	print(*ans[1])





if __name__ == "__main__":
	main()