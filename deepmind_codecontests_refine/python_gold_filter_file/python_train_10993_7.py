n=int(input())
k=0
queue=["Sheldon","Leonard","Penny","Rajesh","Howard"]
if n<=5:
	print(queue[n-1])
else:
	for i in range(30):
		if 10*(2**(i-1))-5<n and 10*(2**(i))-5>=n:
			while k<=i-1 and n>=1:
				n-=5*2**k
				k+=1
			if n/2**(i)<=1:
				print(queue[0])
			elif n/2**(i)<=2:
				print(queue[1])
			elif n/2**(i)<=3:
				print(queue[2])
			elif n/2**(i)<=4:
				print(queue[3])
			else:
				print(queue[4])
			break
