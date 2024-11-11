t = int(input())
b = 0
for i in range(t):
    n = int(input())
    while n > 1:
        if (n % 6) == 0:
            n = n / 6
            b += 1
        else:
            if (n % 3) == 0:
                n = (n * 2) / 6
                b += 2
            else:
                n = -1
    if n == 1:
        print(b)
    else:
        print(-1)
    b = 0