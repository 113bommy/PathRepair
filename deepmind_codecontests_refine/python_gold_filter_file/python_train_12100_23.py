for i in range(int(input())):
	m=list(map(int,input().split()))
	p=m[1]-m[0]
	q=m[2]+m[3]

	print(p//q if p%q==0 else -1)

