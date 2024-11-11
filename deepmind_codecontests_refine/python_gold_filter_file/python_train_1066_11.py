t=int(input())
for i in range(t):
	n,x,m=map(int,input().split())
	x1=x-1
	x2=x-1
	for j in range(m):
		l,d=map(int,input().split())
		if(l-1<=x1<=d-1 or l-1<=x2<=d-1):
			x1=min(x1,l-1)
			x2=max(x2,d-1)
	print(x2-x1+1)
