sigma=lambda n:n*(n+1)//2-1
ll=lambda:list(map(int,input().split()))
[n,v]=ll()
if v+1>=n:
	print(n-1)
else:
	print(v+sigma(n-v))
