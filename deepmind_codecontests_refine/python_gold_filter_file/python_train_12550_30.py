n, c = map(int, input().split())
numbers = list(map(int, input().split()))
result = 1

for i in range(1, n):
    if numbers[i] - numbers[i - 1] <= c:
        result += 1
    else:
        result = 1

print(result)