for _ in range(int(input())):
	n=int(input())
	a=list(map(int,input().split()))
	
	pos=n-1
	while pos>0 and a[pos-1]>=a[pos]:
		pos-=1

	while pos>0 and a[pos-1]<=a[pos]: 
		pos-=1

	print(pos)


