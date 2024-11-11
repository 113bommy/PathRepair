tests = int(input())
for test in range(tests):
	n = int(input())
	a = list(map(int,input().split()))
	for i in range(n):
		if a[i]%2==0:
			print(1)
			print(i+1)
			break
	else:
		if n > 1:
			print(2)
			print(1,2)
		else:
			print(-1)