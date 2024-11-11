q=int(input().strip())

for ii in range(q):
	l,r=(int(i) for i in input().strip().split())
	if l%2!=r%2:
		if l%2==0:
			print(-(r-l+1)//2)
		else:
			print((r-l+1)//2)
	else:
		if l%2==0:
			print((r-l)//2+l)
		else:
			print(-(r-l)//2-l)