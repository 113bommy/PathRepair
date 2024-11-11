def factorial(x):
	if x <= 1:
		return 1
	else:
		return x * factorial(x-1)

n = int(input())

total = 0
for x in range(5, 7+1):
	total += int((factorial(n) / ((factorial(n-x)) * factorial(x))))

print(int(total))