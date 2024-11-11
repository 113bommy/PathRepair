a,b,c = map(int,input().split())
if a <0:
	a = -a
if b<0:
	b = -b
if (c-a-b)%2 == 1 or c<b+a:
	print("No")
else:
	print("Yes")