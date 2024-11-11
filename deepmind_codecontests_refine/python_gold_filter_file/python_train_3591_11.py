n, m = list(map(int, input().split()))
if n == 1:
    print(1)
elif m <= n // 2:
    print(m + 1)
else:
    print(m - 1)
