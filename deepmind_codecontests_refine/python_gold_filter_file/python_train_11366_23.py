s, a, n = map(int, input().split())

while True:
    for i in range(s, 0, -1):
        if s % i == 0 and (n - i) % i == 0:
            n -= i
            break

    if n == 0:
        print(0)
        exit()

    for i in range(a, 0, -1):
        if a % i == 0 and (n - i) % i == 0:
            n -= i
            break

    if n == 0:
        print(1)
        exit()