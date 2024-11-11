n,m=map(int,input().split())
if m==1 and n==1:
	print(1)
elif abs(1-m)>=abs(n-m):
	print(m-1)
else:
	print(m+1)