n,m = [int(i) for i in input().split()]
num = 10**(n-1)
if num+(m-num%m) > 10**n-1:
	print(-1)
else:
	print(num+(m-num%m))
