for i in range(int(input())):
	n = int(input())
	if (n <= 4):
		print([1,1,2,2][n-1])
	else:
		print((n+1)//2)