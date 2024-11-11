n = int(input())
for i in range(n):
	l = []
	j = i +1
	while j <= n**2:
		l.append(j)
		j += 2*n
	j = 2*n-i
	while j <= n**2:
		l.append(j)
		j += 2*n
	print(*l)