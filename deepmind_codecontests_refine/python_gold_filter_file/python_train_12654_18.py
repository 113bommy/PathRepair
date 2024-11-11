n = int(input())
k = []
for i in range(n):
	a = [int(i) for i in input().split()]
	k.append(a)
if n == 1:
	print(1)
else:
	zer = []
	for i in range(n):
		for j in range(n):
			if 0 == k[i][j]:
				zer = [i, j]
	if zer[0] == 0:
		m = sum(k[1])
	else:
		m = sum(k[0])
	k[zer[0]][zer[1]] = m-sum(k[zer[0]])
	if k[zer[0]][zer[1]] > 0:
		y = 1
	else:
		y = 0
	for i in range(n):
		if sum(k[i]) != m:
			y = 0
	for j in range(n):
		u = 0
		for i in range(n):
			u+= k[i][j]
		if u!= m:
			y = 0
	u = 0
	for i in range(n):
		u+=k[i][i]
	if u!= m:
		y = 0
	u = 0
	for i in range(n):
		u+=k[i][n-i-1]
	if u!= m:
		y = 0
	if y == 1:
		print(k[zer[0]][zer[1]])
	else:
		print(-1)
