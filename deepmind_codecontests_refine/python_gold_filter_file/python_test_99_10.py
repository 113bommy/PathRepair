t = int(input())

out = []

for i in range(t):
    x, n = map(int, input(). split())
    tmp = x
    # for j in range(1, n+1):
    #     if x % 2 == 0:
    #         x -= j
    #     else:
    #         x += j
    #     print(x, n%4)

    if tmp % 2 == 0:
        if n % 4 == 3:
            x = tmp + n+1
        elif n % 4 == 1:
            x = tmp - n
        elif n % 4 == 2:
            x = tmp + 1
        elif n % 4 == 0:
            x = tmp
    else:
        if n % 4 == 3:
            x = tmp - n - 1
        elif n % 4 == 1:
            x = tmp + n
        elif n % 4 == 2:
            x = tmp - 1
        elif n % 4 == 0:
            x = tmp
    if n == 0:
        x = tmp
    out.append(x)

for i in range(len(out)):
    print(out[i])
