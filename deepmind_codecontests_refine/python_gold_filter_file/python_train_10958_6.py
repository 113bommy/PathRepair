

for i in range(int(input())):
	x1,y1,z1= list(map(int, input().split()))
	x2,y2,z2= list(map(int, input().split()))

	pos = min(z1, y2)
	y2 = max(0, y2-pos)
	z1 = max(0, z1-pos)

	neg = ( (x1+z1) - z2)
	if neg>0:
		neg = 0
	else:
		neg = -neg

	print(2*(pos-neg))