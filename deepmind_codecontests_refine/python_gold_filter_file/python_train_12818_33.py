n,x,y = map(int,input().split())
a = list(map(int,input().split()))

c = 0
for i in a:
	if i<=x:
		c+=1

if x>y:
	print(n)
else:
	if c%2 ==0:
		print(c//2)
	else:
		print((c//2) + 1)

