for i in range(int(input())):
	n,k=map(int,input().split())
	a=list(map(int,input().split()))
	if len(set(a))==1:
		print(a[0]+k)
	else:	
		c=max(a)
		d=min(a)
		x=(c+d)//2
		if abs(x-d)>k or abs(x-c)>k:
			print(-1)
		elif abs(x-d)<k:
			print(d+k)
		else:
			print(x)