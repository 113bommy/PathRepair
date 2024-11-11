t=int(input())
while(t!=0):
	t-=1
	s=input()
	a=[s.count('L'),s.count('R'),s.count('U'),s.count('D')]
	if (a[0]==0 or a[1]==0 or a[2]==0 or a[3]==0):
		if ((a[0]>0 and a[1]>0)):
			print(2)
			print("LR")
		elif (a[2]>0 and a[3]>0):
			print(2)
			print("UD")
		else:
			print(0)
			print("")
	else:
		p=min(a[0],a[1])
		q=min(a[2],a[3])
		print(2*p+2*q)
		for i in range(p):
			print("L",end="")
		for i in range(q):
			print("U",end="")
		for i in range(p):
			print("R",end="")
		for i in range(q):
			print("D",end="")
		print()
