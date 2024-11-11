a = [3**i for i in range(40)]
for _ in range(int(input())):
	n = int(input())
	x = sum(a)
	for i in a[::-1]:
		if x - i >= n : x -= i
	print(x)