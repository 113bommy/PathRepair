MOD = 1000000007


def fib(n):
    a = b = 1
    for _ in range(n):
        a, b = b, (a + b) % MOD
    return a


def main():
    n, m = map(int, input().split())
    print((fib(n) + fib(m) - 1) * 2 % MOD)


main()
