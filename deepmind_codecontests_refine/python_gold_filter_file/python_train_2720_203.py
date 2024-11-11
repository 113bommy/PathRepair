n=int(input())
if(n==2):
	print(1)
elif(n%2==0 and (n//2)%2==0):
	print(0)
elif(n%2!=0 and ((n+1)/2)%2==0):
	print(0)
else:
	print(1)
