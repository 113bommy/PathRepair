t = int(input())
while t>0:
	t-=1
	a, b, n = input().split()
	a, b, n = int(a), int(b), int(n)
	ans = 0
	while max(a,b) <= n:		
		if a < b:
			a+=b
		else:
			b+=a
		ans+=1
	print(ans)