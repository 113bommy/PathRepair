a, b, c = map(int, input().split())
x, y, z = map(int, input().split())
pos = 0
neg = 0
if x > a:
	pos += x-a
else:
	neg += (a-x)//2
if y > b:
	pos += y-b
else:
	neg += (b-y)//2
if z > c:
	pos += z-c
else:
	neg += (c-z)//2
if pos <= neg:
	print("Yes")
else:
	print('No')