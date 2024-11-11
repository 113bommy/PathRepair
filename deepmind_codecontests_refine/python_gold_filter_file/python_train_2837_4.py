for _ in range(int(input())):
	n, m = map(int, input().split())
	a = []
	for i in range(n):
		a.append(list(map(int, input().split())))
	r1 = 0
	r2 = 0
	for i in range(n):
		if a[i].count(1) == 0:
			r1 += 1
	for j in range(m):
		b = []
		for i in range(n):
			b.append(a[i][j])
		if b.count(1) == 0:
			r2 += 1
	if min(r1, r2) % 2 == 1:
		print('Ashish')
	else:
		print('Vivek')
