t = int(input())

for i in range (t):
	x=input()
	a=int(x.split()[0])
	b=int(x.split()[1])
	p=abs(a-b)
	if p%10 !=0:
		n=(p//10+1)
	else:
		n=int(p/10)

	print (n)
