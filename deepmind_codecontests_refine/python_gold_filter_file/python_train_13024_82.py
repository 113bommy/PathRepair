ns = list(map(int, input().split()))
coins = 0
if 	ns[0] <= ns[1]:
	if ns[1] % ns[0] == 0:
		print(ns[1] // ns[0])
	else:
		print((ns[1] // ns[0]) + 1)
else:
	print(1)