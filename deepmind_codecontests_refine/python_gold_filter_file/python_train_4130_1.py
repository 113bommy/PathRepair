n = int(input())
numbers = list(map(int, input().split()))
# print(numbers)
numbers.reverse()
result = []
for x in numbers:
    if x not in result:
        result.insert(0, x)

print(len(result))
for i in result:
    print(i, end=" ")