for _ in range(int(input())):
	n, m, a, b = map(int, input().split())
	if n * a != m * b:
		print('NO')
		continue
	print('YES')
	arr = [[0] * m for i in range(n)]
	j = 0
	for i in range(n):
		for k in range(a):
			arr[i][j] = 1
			j = (j + 1) % m
	for i in arr:
		print(*i, sep='')