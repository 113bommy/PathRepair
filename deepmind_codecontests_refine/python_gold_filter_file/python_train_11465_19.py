n = int(input())

for i in range(n):
	d = int(input())

	det = d*d - 4*d
	if det < 0:
		print("N")

	else:
		print("Y",(d + det**(1/2))/2,(d-det**(1/2))/2)