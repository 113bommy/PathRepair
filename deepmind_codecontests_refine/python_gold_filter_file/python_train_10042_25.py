x = int(input())
for i in range(1, 100):
    if (i ** 2 + i) // 2 == x:
        print('YES')
        exit(0)
print('NO')