A,B,C=map(int,input().split())
if (A+B-C)**2>4*A*B and (A+B)<C:
	print("Yes")
else:
	print("No")