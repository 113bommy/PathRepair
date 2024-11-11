n, k = map(int, input().split())
for i in range(n + 1):
    if i * (i - 1) // 2 >= k:
        exit(print(max(n - k * 2, 0), n - i))