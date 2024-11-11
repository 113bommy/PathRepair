import math
x = y = n= 0
while True:
	d,a = map(int,input().split(','))
	if d == a == 0: break
	x += d*math.sin(math.radians(n))
	y += d*math.cos(math.radians(n))
	n+=a
print(*map(int,(x,y)),sep='\n')
