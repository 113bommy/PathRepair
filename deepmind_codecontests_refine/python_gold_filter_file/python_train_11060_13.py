for nt in range(int(input())):
	n=int(input())
	if n%4!=0:
		print ("NO")
	else:
		print ("YES")
		a,b=0,0
		for i in range(n//2):
			print (2*(i+1),end=" ")
			a+=2*(i+1)
		for i in range(n//2-1):
			print (2*(i)+1,end=" ")
			b+=2*i+1
		print (a-b)