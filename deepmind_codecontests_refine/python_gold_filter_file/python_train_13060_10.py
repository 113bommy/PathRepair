n=int(input())
if n%2==0 and (n/2)%2==0:
	print(int(n/2),int(n/2))
else:
	found=0
	even=4
	while found==0:
		a=n-even
		i=2
		while i<(a/2)+1:
			if a%i==0:
				print(even,a)
				found=1	
				break
			i+=1
		even+=2
