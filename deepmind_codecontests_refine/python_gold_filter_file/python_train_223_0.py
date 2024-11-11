for i in range(int(input())):
	a,b,n=map(int,input().split())
	if(n%3==0):
		print(a)
	elif(n%3==1):
		print(b)
	else:
		print(a^b)