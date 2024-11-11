for _ in range(int(input())):
	n = int(input())
	a = sorted(list(map(int,input().split())))
	a.reverse()
	if n==2: print(0)
	elif n==3:
		if a[1]>1: print(1)
		else: print(0)
	else:
		for i in range(1,n-1):
			if a[1] > n-1-i:
				print(n-1-i)
				break
		else:
			print(0)