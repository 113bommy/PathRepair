r,c=map(int,input().split())

if r==1 and c==1:
	print(0)
elif(r==1 and c>1):
	for i in range(c):
		print(i+2,end=" ")
	print()
elif (r>1 and c==1):
	for i in range(r):
		print(i+2)
else:
	if r<=c:
		for i in range(r):
			for j in range(c):
				print((c+i+1)*(j+1),end=" ")
			print()
	else:
		for i in range(r):
			for j in range(c):
				print((i+1)*(r+j+1),end=" ")
			print()
