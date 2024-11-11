nb = int(input())
numbers = sorted([int(x) for x in input().split()])
for i in range(2, nb, 2):
    numbers[i-1], numbers[i] = numbers[i], numbers[i-1]
print(*numbers)