import math
import string

t = int(input())

for tt in range(t):
	n, m = map(int, input().split())
	a = []
	for i in range(n):
		a.append(int(input(), 2))

	need = (2 ** m - n - 1) // 2
	l = 0
	r = 2 ** m
	while(r - l > 1):
		mid = (l + r) // 2
		x = mid
		for i in range(n):
			if(a[i] < mid):
				x -= 1
		if(x > need):
			r = mid
		else:
			l = mid
	ans = []
	for i in range(m):
		ans.append(l % 2)
		l //= 2
	ans.reverse()
	for i in range(m):
		print(ans[i], end="")
	print()
