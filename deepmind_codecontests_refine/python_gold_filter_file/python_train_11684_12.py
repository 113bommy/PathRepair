t=int(input())

for i in range(t):
	length=int(input())
	a=list(map(int,input().split(" ")))
	if (length==1 and a[0]%2==0):
		print(1)
		print(1)
	elif(length==1 and a[0]%2!=0):
		print(-1)
	if (length!=1):
		flag=0
		for j in range(2):
			if (a[j]%2==0):
				print(1)
				print(j+1)
				flag=1
				break

		if (flag==0):
			print(2)
			print(1,2)