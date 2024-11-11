
t=int(input())
while t>0:
	t-=1
	a,b=map(int,input().split())
	if b>a:
		temp=b
		b=a
		a=temp
	a=a-b
	count=0
	while a!=0:
		if a>=5:
			t1=a
			a=a%5
			count+=int(t1/5)
		if a>=2:
			t2=a
			a=a%2
			count+=int(t2/2)
		if a==1:
			t3=a
			a=a-1
			count+=int(t3)
	print(count)