for nt in range(int(input())):
	n=int(input())
	ans=0
	while n//10>=1:
		ans+=n-n%10
		n=n//10+n%10
	print (ans+n)