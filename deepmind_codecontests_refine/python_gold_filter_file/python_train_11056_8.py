for _ in range(int(input())):
	x,y=map(int,input().split())
	print('NO' if x in [2,3] and y>=4 or x==1 and y>x else 'YES')