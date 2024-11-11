import os
import sys
if os.path.exists('/mnt/c/Users/Square/square/codeforces'):
	f = iter(open('B.txt').readlines())
	def input():
		return next(f)
	# input = lambda: sys.stdin.readline().strip()	
else:
	input = lambda: sys.stdin.readline().strip()

fprint = lambda *args: print(*args, flush=True)

t = int(input())
for _ in range(t):
	n, x, y = map(int, input().split())

	r1 = n-y-1
	r2 = n-x-1
	# print(r1, r2)
	u = min(n, max(1, n - r1 - r2 - 1))
	# v = min(n, min(n-x, y-1) + min(n-y, x-1) + 1)
	v = min(n, x+y-1)
	print(u, v)

