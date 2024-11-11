for i in range(int(input())):
	s,a,b,c=map(int,input().split())
	print(((s//c)//a)*b+(s//c))