t=int(input())
for _ in range(t):
	a,b,n= map(int,input().split(" "))
	movesa=0
	movesb=0
	
 
	if(a>=b):
		while(a<=n):
			b+=a
			movesa+=1

			if(b>n):
				break
			else:
				val = a+b
				if(val>n):
					movesa+=1
					break
				else:
					a+=b
					movesa+=1

	else:
		while(b<=n):
			a+=b
			movesb+=1
			if(a>n):
				break
			else:
				val=b+a
				if(val>n):
					movesb+=1
					break
				else:
					b+=a
					movesb+=1 
 
	print(max(movesa,movesb))