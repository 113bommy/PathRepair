t=int(input())
for _ in range(t):
	n=int(input())
	a=list(map(int,input().split()))
	m=a[n-1]
	c=0
	for i in range(n-2,-1,-1):
		if(a[i]<=m):
			m=a[i]
			continue
		else:
			c+=1
	print(c)

