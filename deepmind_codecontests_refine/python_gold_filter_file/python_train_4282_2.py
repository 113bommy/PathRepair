def mynfn():
	x=input().split(" ")
	n=int(x[0])
	s=int(x[1])
	y=input().split(" ")
	min=1000000000000
	sum=0
	k=0
	for i in range(len(y)):
		y[i]=int(y[i])
		if y[i]<min:
			min=y[i]
			k=i
		sum=sum+y[i]
	if sum<s:
		print("-1")
	else:
		a=sum-min*n
		if a>=s:
			print(min)
		else:
			h1=int((s-a)/n)
			h2=(s-a)%n
			if h2==0:
				print(min-h1)
			else:
				print(min-h1-1)
mynfn()