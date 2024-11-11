n = int(input())
for i in range(n):
	k = int(input())
	ma = 0
	mb = 10000000000
	for j in range(k):
		a, b = [int(i) for i in input().split()]
		if a>ma:
			ma = a
		if b<mb:
			mb = b
	print(ma-mb if ma-mb>-1 else 0)