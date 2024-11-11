t = int(input())
for i in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	su = sum(arr)
	xor = 0
	for x in arr:
		xor = xor^x

	print(2)
	print(xor, su+xor)