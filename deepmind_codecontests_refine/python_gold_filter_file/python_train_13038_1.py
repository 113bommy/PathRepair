for ad in range(int(input())):
    n, m = list(map(int, input().split()))
    if m % 2 == 0:
        print(n * m // 2)
    elif n % 2 == 0 and m % 2 == 1:
        print((n * (m-1) )// 2 + (n // 2))
    else:
        print((n) * (m-1) // 2 + (n // 2) + 1)
