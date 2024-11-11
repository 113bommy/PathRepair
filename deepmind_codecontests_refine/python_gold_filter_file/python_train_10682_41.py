a,b,c = map(int,input().split())
if c<=b:
	print(c)
elif c>b and c<a:
	print(b)
elif c>=a:
	print(b+a-c)