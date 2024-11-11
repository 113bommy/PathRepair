n=int(input())
for i in range(n//2):
	for j in range(n):
		if j<n//2-i or j>n//2+i:
			print('*',end='')
		else:
			print('D',end='')
	print()
for i in range(n//2,n):
	for j in range(n):
		if j<n//2 -n+1+i or j>n//2 +n-1-i:
			print('*',end='')
		else:
			print('D',end='')
	print()