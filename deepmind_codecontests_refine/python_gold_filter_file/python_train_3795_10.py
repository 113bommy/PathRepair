n=int(input())
x=''
for a in range(1,int((n+3)/2)):
	b=(n+1-2*a)/2
	x+=int(b)*'*'
	x+=(2*a-1)*'D'
	x+=int(b)*'*'
	print(x)
	x=''
for a in range(1,int((n+1)/2)):
	b=n-2*a
	x+=a*'*'
	x+=b*'D'
	x+=a*'*'
	print(x)
	x=''