count = 0
for _ in range(int(input())):
    a, b = map(int, input().split())
    if b-a > 1:
        count += 1
print(count)