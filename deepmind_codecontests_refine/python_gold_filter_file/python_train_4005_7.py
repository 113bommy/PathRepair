for _ in range(int(input())):
	m,n=map(int,input().split())

	while(m|(m+1)<=n):
		m|=(m+1)
	print(m)