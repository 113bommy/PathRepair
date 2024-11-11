n, k = map(int, input().split())
if n == k or k == 0:
    print(0, 0)
else:
    x = n // 3
    if k <= x:
        print(1, k * 2)
    else:
        print(1, n - k)