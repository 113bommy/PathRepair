for i in range(int(input())):
	x=0
	e=0
	s,a,b,c=map(int,input().split())
	x=s//c
	e=(x//a)*b
	print(x+e)