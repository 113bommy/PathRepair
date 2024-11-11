
num_q = int(input())
inps = []
for i in range(num_q):
	inps.append(int(input()))
for i in inps:
	if i <= 2:
		print(4-i)

	elif i % 2 == 0:
		print("0")
	else:
		print("1")