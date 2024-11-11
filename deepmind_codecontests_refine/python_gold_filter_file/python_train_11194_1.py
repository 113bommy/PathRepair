n=input()
llist=[]
llist=n.split()
kol=int(llist[0])
a=int(llist[1])
b=int(llist[2])
if a*b<kol:
	print(-1)
else:
	for i in range(a):
		if i%2==0:
			for j in range(b):
			    if i*b+j+1<=kol:
			        print(i*b+j+1, end = ' ')
			    else:
			        print('0', end=' ')
			print(' ')
		else:
			for j in range(b):
			    if (i+1)*b-j<=kol:
			        print((i+1)*b-j, end = ' ')
			    else:
			        print('0', end=' ')
			print(' ')
	