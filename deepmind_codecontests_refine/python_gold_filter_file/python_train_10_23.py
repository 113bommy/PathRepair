for _ in range(int(input())):
	a,b,d=map(int,input().split())
	m1=a%d
	m2=b%d
	if m1!=0 and a//d!=0:
		print(d)
	elif m1==0 and a//d>=2:
		print(d)
	else:
		print(d*(b//d+1))
