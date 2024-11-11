n = int(input())
mid = n // 2
for g in range(n):
    for i in range(mid):
        print(n * i + g + 1, end=' ')
    for i in range(mid, n):
        print(n * i + (n - g), end=' ')
    print()