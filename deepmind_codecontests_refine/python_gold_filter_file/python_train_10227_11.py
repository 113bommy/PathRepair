for nt in range(int(input())):
	n,k=map(int,input().split())
	if k==1 and n%2:
		print ('YES')
		continue
	if n<k**2 or n%2!=k%2:
		print ("NO")
		continue
	print ("YES")