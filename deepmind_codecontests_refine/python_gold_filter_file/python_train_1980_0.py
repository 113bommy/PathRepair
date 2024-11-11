n = int(input())

first = 1
second = 1
for i in range(n-1):
    second, first = first + second, second
print(second)