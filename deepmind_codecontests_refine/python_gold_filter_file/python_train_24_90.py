t=int(input())
for tt in range(t):
	n=int(input())
	a=[int(x) for x in input().split(' ')]
	a.sort()
	if(a[0]+a[1]>a[-1]):
		print(-1)
	else:
		print(1,2,n)