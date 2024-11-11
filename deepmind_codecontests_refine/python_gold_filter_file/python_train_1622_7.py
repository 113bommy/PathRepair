n = int(input())
a = [int(i) for i in input().split()]

import sys

if n == 1:
	print("NO" if a[0] == 0 else "YES\n1\n1 1")
else:
	sol = []
	start = 0
	for i in range(n):
		if sum(a[start:i + 2]) == 0 and sum(a[start:i + 1]) != 0:
			sol += [(str(start + 1), str(i + 1))]
			start = i + 1
	if sum(a[start:n]) != 0:
		sol += [(str(start + 1), str(n))]
		print("YES")
		print(len(sol))
		for i in sol:
			print(' '.join(i))
	else:
		print("NO")
