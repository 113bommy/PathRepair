s,a,b,a1,b1=map(int,input().split())
a=s*a+2*a1
b=s*b+2*b1

if b>a:
	print('First')
elif a>b:
	print("Second")
else:
	print("Friendship")

