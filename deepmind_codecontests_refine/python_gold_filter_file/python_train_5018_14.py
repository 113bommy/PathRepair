n = int(input())
l = [-5, -2, -1, 1, 2, 5]
for i in range(n):
	a,b = map(int,input().split())
	if a==b:
		print(0)
		continue
	count = 0
	c = abs(a-b)
	if c>=5:
		count+=c//5
		c%=5
	if c>=2:
		count+=c//2
		c = c%2
	count+=c
	print(count)