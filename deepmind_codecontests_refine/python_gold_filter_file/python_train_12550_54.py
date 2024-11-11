string = input()
numbers = string.split(" ")
n = int(numbers[0])
c = int(numbers[1])
string = input()
numbers = string.split(" ")
for x in range(n):
    numbers[x] = int(numbers[x])
words = 1
for x in range(n - 1):
    if numbers[x + 1] - numbers[x] > c:
        words = 0
    words += 1
print(words)