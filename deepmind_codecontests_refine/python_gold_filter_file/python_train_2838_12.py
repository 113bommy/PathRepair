for i in range(int(input())):
	x,y,z=list(map(int,input().split()))
	if x==y and z<=x:
		print('YES')
		print(x,z,z)
	elif x==z and y<=x:
		print('YES')
		print(y,x,y)
	elif y==z and x<=y:
		print('YES')
		print(x,x,y)
	else:
		print('NO')