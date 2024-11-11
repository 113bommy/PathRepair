for _ in range(int(input())):
    x, y, n = map(int, input().split())
    a = n // x
    if n % x < y:
        print((a - 1) * x + y)
    else:
        print(a * x + y)
