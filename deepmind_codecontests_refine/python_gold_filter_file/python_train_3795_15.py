n = int(input())
for i in range(n // 2):
    print((n - (2 * i + 1)) // 2 * '*' + (1 + 2 * i) * 'D' + (n - (2 * i + 1)) // 2 * '*')
print(n * 'D')
for i in range(n // 2 - 1, -1, -1):
    print((n - (2 * i + 1)) // 2 * '*' + (1 + 2 * i) * 'D' + (n - (2 * i + 1)) // 2 * '*')
