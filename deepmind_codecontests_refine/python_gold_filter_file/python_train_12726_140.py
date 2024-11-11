t=int(input()) 
for _ in range(t):
	n,k=map(int,input().split())
	if(n>2):
		print(2*k)
	elif(n==1):
		print(0)
	else:
		print(k)