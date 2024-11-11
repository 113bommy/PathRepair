
nBox = int(input())
userInput = input()
data = userInput.split()
data = map(int, data)

arr = []

for i in data:
	arr.append(i)

arr = sorted(arr)

for i in arr:
	print(i, end = ' ')