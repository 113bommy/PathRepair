a,b=map(int,input().split())

x=a%b

while x>0:
	a=b
	b=x
	x=a%b

print(b)
