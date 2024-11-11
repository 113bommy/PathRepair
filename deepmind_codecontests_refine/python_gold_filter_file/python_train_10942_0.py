n = int(input())
for i in range(n):
	a,b,c,d = map(int,input().split())
	z = a//d
	x = z//b
	v = x*c
	print(z+v)