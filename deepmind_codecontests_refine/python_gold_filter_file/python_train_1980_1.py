def fib(n):
    n1 = n2 = tmp = 1
    for _ in range(n - 1):
        tmp = n1 + n2
        n1, n2 = n2, tmp
    return tmp

print(fib(int(input())))