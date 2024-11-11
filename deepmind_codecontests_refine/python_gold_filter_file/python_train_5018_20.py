for _ in range(int(input())):
	n,k = map(int,input().split())
	# a = list(map(int, input().split()))
	if(n<k):
		n,k=k,n
	d=n-k
	ans=d//5
	r=d%5
	if(r==0):
		print(ans)
	elif(r==1 or r==2):
		print(ans+1)
	else:
		print(ans+2)

