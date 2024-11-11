def isPrime(n):
	x=int(n**(0.5))
	for i in range(3,x+1,2):
		if n%i==0:
			return False
			break
	return True
for t in range(int(input())):
	n=int(input())
	if n==1:
		print("FastestFinger")
	elif n==2:
		print("Ashishgup")
	elif n%2!=0:
		print("Ashishgup")
	else:
		d=0
		i=0
		while n%(2**i)==0:
			i+=1
		i-=1
		x=n//(2**i)
		


		if x==1:
			print("FastestFinger")

		elif n%4!=0:
			if isPrime(x):
				print("FastestFinger")
			else:
				print("Ashishgup")
		else:
			print("Ashishgup")


