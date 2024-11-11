n=int(input())
k=-1
for i in range(n+1):
	k=-1
	for j in range(2*(n-i)-1):
		print(" ",end="")
	for j in range(2*i+1):
		
		if j<(2*i+2)//2:
			k+=1

			if i==n and j==0:
				print(str(k),end="")
			else:
				print(" "+str(k),end="")
			
		else:
			k-=1
			
			print(" "+str(k),end="")
			
	print()


k=-1
for i in range(n-1,-1,-1):
	k=-1
	for j in range(2*(n-i)-1):
		print(" ",end="")
	for j in range(2*i+1):

		if j<(2*i+2)//2:
			k+=1
			print(" "+str(k),end="")
			
		else:
			k-=1
			
			print(" "+str(k),end="")
			

	print()