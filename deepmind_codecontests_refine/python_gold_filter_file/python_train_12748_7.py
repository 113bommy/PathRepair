n = int(input())
x, y = 1, 1
for i in range(n-1):
	x += y
	y += 1
	if x % n == 0:
		print(n, end=' ')
	else:
		print(x % n, end=' ')