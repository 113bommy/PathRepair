for _ in range(int(input())):
	a,b,c=map(int,input().split())
	if(a>=c):
		print(-1,b)
	else:
		print(1,end=" ")
		if a*b<=c:
			print(-1)
		else:
			print(b)

