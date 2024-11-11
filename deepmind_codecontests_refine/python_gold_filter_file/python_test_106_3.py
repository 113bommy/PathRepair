t=int(input())
for _ in range(t):
	n=int(input())
	m=[]
	for i in range(2,n+2):
		m.append(i)
	print(*m)