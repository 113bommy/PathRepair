def solve():

    n, k = [int(x) for x in input().split(' ')]
    x = n // ((k * (k + 1)) // 2)

    r = 1
    i = 2
    while i * i <= n:
        if n % i == 0:
            if i <= x:
                r = max(i, r)
            if n // i <= x:
                r = max(n // i, r)
        i += 1

    if n <= x:
        r = n

    if n < (k * (k + 1)) // 2:
        return [-1]

    else:
        y = [r * i for i in range(1, k + 1)]
        y[-1] += n - sum(y)
        return y


print(*solve())