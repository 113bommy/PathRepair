n, m = list(map(int, input().split()))
a=[]
for i in range(n):
	a.append([int(j) for j in input().split()])
b = []
for i in range(m):
	b.append(int(input()))
for i in range(n):
	s = 0
	for j in range(m):
		s += a[i][j] * b[j]
	print(s)
	
