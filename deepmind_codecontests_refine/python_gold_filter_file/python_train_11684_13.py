t = int(input())

for _ in range(t):
	
	n = int(input())
	a = list(map(int, input().split(' ')))
	
	if n==1:
		if a[0]%2==0:
			print(1)
			print(1)
		else:
			print(-1)
	
	else:
		if (a[0]+a[1])%2==0:
			print(2)
			print('1'+" "+'2')
		else:
			if a[0]%2==0:
				print(1)
				print(1)
			elif a[1]%2==0:
				print(1)
				print(2)
