n,a,b=map(int,input().split())
if (b-a)%2==0:
	print(int((b-a)//2))
else:
	s=min(a-1,n-b)
	print(int(s+1+(b-a-1)//2))
