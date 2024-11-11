for _ in range(int(input())):
	a,b,c,d = map(int,input().split())
	if a+b>c:
		print(a,b,c)
	else:
		print(b,c,c)