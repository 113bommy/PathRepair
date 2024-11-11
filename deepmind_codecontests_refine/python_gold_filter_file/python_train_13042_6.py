def correct(x, y):
	a[x][y] = 0
	ans.append([x+1, y+1, x+2, y+1, x+2, y+2])	
	a[x+1][y+1] = 1 - a[x+1][y+1]
	a[x+1][y] = 1 - a[x+1][y]

def makeone(i):
	a[-1][i] = a[-1][i+1] = a[-2][i] = a[-2][i+1] = 0

def one(i):
	if a[-2][i]:
		ans.append([n-1, i+2, n, i+1, n-1, i+1])
		a[-2][i] = 0
		a[-2][i+1] = a[-1][i] = 1
	elif a[-2][i+1]:
		ans.append([n-1, i+1, n, i+1, n-1, i+2])
		a[-2][i+1] = 0
		a[-2][i] = a[-1][i] = 1
	elif a[-1][i]:
		ans.append([n-1, i+1, n-1, i+2, n, i+1])
		a[-1][i] = 0
		a[-2][i] = a[-2][i+1] = 1
	else:
		ans.append([n-1, i+1, n-1, i+2, n, i+2])
		a[-1][i+1] = 0
		a[-2][i] = a[-2][i+1] = 1
	# print (a)
	two(i)

def two(i):
	if a[-1][i]:
		if a[-1][i+1]:
			ans.append([n-1, i+1, n-1, i+2, n, i+1])
			ans.append([n-1, i+1, n-1, i+2, n, i+2])
		elif a[-2][i]:
			ans.append([n-1, i+2, n, i+2, n, i+1])
			ans.append([n-1, i+2, n-1, i+1, n, i+2])
		elif a[-2][i+1]:
			ans.append([n-1, i+1, n-1, i+2, n, i+2])
			ans.append([n-1, i+1, n, i+1, n, i+2])
	elif a[-2][i]:
		if a[-2][i+1]:
			ans.append([n-1, i+2, n, i+2, n, i+1])
			ans.append([n-1, i+1, n, i+1, n, i+2])
		elif a[-1][i+1]:
			ans.append([n-1, i+2, n, i+2, n, i+1])
			ans.append([n-1, i+1, n-1, i+2, n, i+1])
	else:
		ans.append([n-1, i+1, n-1, i+2, n, i+1])
		ans.append([n-1, i+1, n, i+1, n, i+2])
	makeone(i)

def final(i, c):
	if c==1:
		one(i)
	elif c==4:
		ans.append([n-1, i+2, n, i+1, n, i+2])
		a[-2][i+1] = a[-1][i] = a[-1][i+1] = 0
		one(i)
	elif c==3:
		if not a[-2][i]:
			ans.append([n-1, i+2, n, i+1, n, i+2])
		elif not a[-2][i+1]:
			ans.append([n-1, i+1, n, i+1, n, i+2])
		elif not a[-1][i]:
			ans.append([n-1, i+1, n-1, i+2, n, i+2])
		else:
			ans.append([n-1, i+1, n-1, i+2, n, i+1])
		makeone(i)
	elif c==2:
		two(i)


def count(i):
	c = 0
	if a[-1][i]:
		c += 1
	if a[-1][i+1]:
		c += 1
	if a[-2][i]:
		c += 1
	if a[-2][i+1]:
		c += 1
	# print (c)
	final(i, c)

for nt in range(int(input())):
	n,m = map(int,input().split())
	a, ans = [], []
	for i in range(n):
		a.append(list(map(int,list(input()))))
	for i in range(n-2):
		for j in range(m-1):
			if a[i][j]==1:
				correct(i, j)
		if a[i][-1] == 1:
			ans.append([i+1, m, i+2, m, i+2, m-1])
			a[i][-1] = 0
			a[i+1][-1] = 1 - a[i+1][-1]
			a[i+1][-2] = 1 - a[i+1][-2]


	# print (a)

	if m%2:
		if a[-1][-1] and a[-2][-1]:
			for i in range(0, m-1, 2):
				count(i)
			count(m-2)
		elif not a[-1][-1] and not a[-2][-1]:
			for i in range(0, m-1, 2):
				count(i)
		else:
			for i in range(0, m-3, 2):
				count(i)
			# print (a)
			if a[-1][-1]:
				ans.append([n-1, m-1, n, m-1, n, m])
				a[-2][-2] = 1 - a[-2][-2]
				a[-1][-2] = 1 - a[-1][-2]
				a[-1][-1] = 0
				count(m-3)
			else:
				ans.append([n-1, m-1, n, m-1, n-1, m])
				a[-2][-2] = 1 - a[-2][-2]
				a[-1][-2] = 1 - a[-1][-2]
				a[-2][-1] = 0
				count(m-3)

	else:
		for i in range(0, m, 2):
			count(i)
			# print (a)

	# print (a)
	print (len(ans))
	for i in ans:
		print (*i)

