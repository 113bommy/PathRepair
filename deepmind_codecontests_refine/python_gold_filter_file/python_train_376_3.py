n=int(input())
m=int(input())
x=abs(m-n)
y=int(x/2)
if x%2==0:
	print(y*(y+1))
else:
	print((y*(y+1)+y+1))