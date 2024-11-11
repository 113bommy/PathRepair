n, k, t=map(int, input().split())

if k<=t<=n:
	print(k)
else:
	if t>n:
		print(k-(t%n))
	else:
		print(t%k)