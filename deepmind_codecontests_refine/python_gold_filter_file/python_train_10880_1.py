n=int(input())
x=n//4
if n%4==0:
	x-=1
if n%2==1:
	x=0
print(x)