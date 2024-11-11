# your code goes here
import math

n = int(input())
for i in range(n):
	xa, ya, ra, xb, yb, rb = [float(x) for x in input().split(" ")]
	distance = math.sqrt((xb-xa)**2 + (yb-ya)**2)

	if distance > ra+rb:
		print(0)
	elif distance < abs(ra-rb):
		if ra > rb:
			print(2)
		elif ra < rb:
			print(-2)
		else:
			print(1)
	elif distance <= ra+rb:
		print(1)
			