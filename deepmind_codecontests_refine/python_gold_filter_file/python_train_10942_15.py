for _ in range(int(input())):
	s,a,b,c=map(int,input().split())
	print(((s//(a*c))*b)+s//c)