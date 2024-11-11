T1, T2 = map(int, input().split())
A1, A2 = map(int, input().split())
B1, B2 = map(int, input().split())

X1 = T1 * (A1 - B1)
X2 = T2 * (A2 - B2)

D = X1 + X2
if D == 0:
	print("infinity")
else:
	if X1 < 0:
		X1, X2 = [-X1, -X2]
	else:
		D = -D
	
	if D < 0:
		print("0")
	else:
		if X1 % D == 0:
			print((X1 // D) * 2)
		else:
			print((X1 // D) * 2 + 1)
	

