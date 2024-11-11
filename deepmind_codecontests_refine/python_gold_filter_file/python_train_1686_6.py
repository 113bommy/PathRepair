n = int(input())
for i in range(n):
    for j in range(n):
        if j % 2:
            print((n - i - 1) % n + j * n + 1, end=' ')
        else: print(i + j * n + 1, end=' ')
    print()