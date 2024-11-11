inputs = input()
n, k = inputs.split(" ")
n, k = int(n), int(k)

for i in range(k):
	if n % 10 == 0:
		n /= 10
	else:
		n -= 1

print(int(n))
