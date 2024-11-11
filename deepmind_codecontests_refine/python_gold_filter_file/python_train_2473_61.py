rounds = int(input())
numbers = [int(x) for x in input().split(' ')]

numbers = sorted(numbers)

for i in range(rounds-1):
	if (i+1) % 2 == 1:
		numbers.pop(-1)
	else:
		numbers.pop(0)

print(numbers[0])
