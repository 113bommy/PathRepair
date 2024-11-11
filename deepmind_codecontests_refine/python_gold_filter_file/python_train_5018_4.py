query=int(input())

for _ in range(query):
	a, b = map(int, input().split())
	c=0;d=abs(a-b)
	if d==8:
		print(3)
	else:
		c+=(d//5)
		d=d%5
		c+=(d//2)
		d=(d%2)
		c+=(d//1)
		print(c)