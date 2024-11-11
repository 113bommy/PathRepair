for z in range(int(input())):
	a,b,c=map(int,input().split())
	p,q=-1,-1
	if a<c:
		p=1
	if c<b*a:
		q=b
	print(p,q)