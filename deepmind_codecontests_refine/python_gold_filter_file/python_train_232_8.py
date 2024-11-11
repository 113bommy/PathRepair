n=int(input())
a=list(map(int,input().split()))
c=[]
k=[]
if n==1:
	print(1,1)
	print(0)
	print(1,1)
	print(0)
	print(1,1)
	print(-a[0])
else:
	print(1,1)
	print(-a[0])
	print(1,n)
	for i in range(1,n):
		c.append(-n*a[i])
		k.append((n-1)*a[i])
	print(0,*c)
	print(2,n)
	print(*k)
