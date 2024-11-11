for i in range(int(input())):
	n,m=map(int,input().split())
	a=list(map(int,input().split()))
	if n>m or n<=2:
		print(-1)
	elif n<=m:
		print(sum(a)*2)
		for i in range(1,n):
			print(i,i+1)
		print(1,n)	