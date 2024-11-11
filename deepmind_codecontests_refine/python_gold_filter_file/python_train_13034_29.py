for _ in range(int(input())):
	n=int(input())
	a=list(map(int,input().split()))
	t=sum(a)
	c=0
	for x in a:
		c^=x
	print(2)
	print(c,t+c)