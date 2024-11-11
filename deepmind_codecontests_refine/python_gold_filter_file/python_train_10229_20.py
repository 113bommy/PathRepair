for w in range(int(input())):
    a, b, n = (int(x) for x in input().split())
    u = 0
    while a <= n and b <= n:
        if a > b:
            b += a
        else:
            a += b
        u += 1
    print(u)