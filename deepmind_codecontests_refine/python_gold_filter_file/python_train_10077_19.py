m, d = map(int, input().split())
count = 0
for i in range(2, 10):
    for j in range(2, 10):
        if 10 * i + j <= d and i * j <= m:
            count += 1
print(count)