a,b=map(int,input().split())
c=0
if a%2==0:
	c+=a//2
else:
	c+=(a//2)+1
if a==b:
	print(a)
else:
	if a<b:
		print('-1')
	elif c%b==0:
		print(c)
	else:
		print(((c//b)+1)*b)