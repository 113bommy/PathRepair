n,m,k=map(int,input().split())
if k<m<=k+n:
	t=1
	for i in range(k+1):
		t*=(m-i)/(n+k-(i-1))
	print(1-t)
else:
	print(0 if m>n+k else 1)
