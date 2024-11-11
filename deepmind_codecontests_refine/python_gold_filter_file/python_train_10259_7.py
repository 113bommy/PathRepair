a,b,n,x=map(int, input().split());
m=1000000007;
def modex(a,n):
	ans=1
	while n:
		if n&1:
			ans=(ans%m*a%m)%m
		a=(a%m*a%m)%m
		n>>=1
	return ans
if a==1:
	print((x%m+(b%m*n%m)%m)%m)
else:
	print(((modex(a,n)%m*x%m)%m+(b%m*((modex(a,n)%m-1%m)%m)%m*(modex(a-1,m-2)))%m)%m)