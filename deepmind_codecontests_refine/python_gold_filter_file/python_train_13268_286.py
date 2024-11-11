count = 0
for __ in range(int(input())):
    a, b = map(int, input().split())
    if b-a >= 2:
        count += 1
print(count)