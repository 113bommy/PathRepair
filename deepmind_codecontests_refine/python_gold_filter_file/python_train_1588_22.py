from math import tan,pi
for _ in range(int(input())):
	n = int(input())
	angle = pi/(2*n)
	ans = 1/tan(angle)	
	print("{:.9f}".format(ans))