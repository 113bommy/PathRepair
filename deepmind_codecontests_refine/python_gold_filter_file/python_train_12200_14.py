
from math import *
n = int(input())
 
a = []
for i in range(n):
	a.append(list(map(int, input().split())))
 
x = 0
for i in range(n):
	x = gcd(x, a[0][i])
ans = [0] * n
#print(x)
for k in range(1, int(x ** 0.5 + 0.5) + 1):
	if x % k == 0:
		ans[0] = k
		for i in range(1, n):
			ans[i] = a[0][i] // k
		#print(ans)
		f = True
		for i in range(n):
			for j in range(i + 1, n):
				if i != j:
					if ans[i] * ans[j] != a[i][j]:
						f = False
						break
			if not f:
				break
		if f:
			print(*ans)
			exit(0)
		k = x // k
		ans[0] = k
		for i in range(1, n):
			ans[i] = a[0][i] // k
		#print(ans)
		f = True
		for i in range(n):
			for j in range(i + 1, n):
				if i != j:
					if ans[i] * ans[j] != a[i][j]:
						f = False
						break
			if not f:
				break
		if f:
			print(*ans)
			exit(0)
 