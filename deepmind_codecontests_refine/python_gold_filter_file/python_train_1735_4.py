def f(n, b, c=0):
    while n % b == 0:
        n //= b
        c += 1
    return c
n, a = int(input()), [int(i) for i in input().split()]
print(*sorted(a, key = lambda x: (f(x, 2), -f(x, 3))))
