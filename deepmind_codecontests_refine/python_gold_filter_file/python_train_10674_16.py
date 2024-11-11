n = int(input())
if n == 1:
    print(0, 1)
else:
    if n % 7 == 1:
        print(2 * n // 7, 2 * n // 7 + 1)
    elif n % 7 == 2:
        print(2 * n // 7, 2 * n // 7 + 2)
    elif n % 7 == 6:
        print(2 * n // 7, 2 * n // 7 + 1)
    elif n % 7 == 0:
        print(2 * n // 7, 2 * n // 7)
    else:
        print(2 * (n // 7), 2 * (n // 7) + 2)
