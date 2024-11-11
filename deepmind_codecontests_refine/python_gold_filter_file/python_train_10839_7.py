#the first integer is the number of queries
t=int(input())
while t>0:
	t-=1
	a,b,k=map(int,input().split())
	if k%2==0:
		print((k//2)*(a-b))
	else:
		print((k//2)*(a-b)+a)
