n = int(input())
numOfPeople = list(map(int, input().split(' ')))
counter = 0

while n > 1:
	counter = counter + 2*(numOfPeople[n-1]*((2*n)- 2))
	n = n - 1

print(counter)
