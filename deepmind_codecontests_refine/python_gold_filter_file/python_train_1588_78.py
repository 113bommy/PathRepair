from math import pi, tan

for _ in range(int(input())):
	n = int(input())
	angle = (pi/2) * ((n-1)/n)
	print(tan(angle))
