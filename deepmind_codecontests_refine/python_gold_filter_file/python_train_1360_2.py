d = 1000000007

def pow_rem(x, n):
    if n == 0:
        return x ** n % d
    if n % 2 == 0:
        return pow_rem(x, n // 2) ** 2 % d
    else:
        return ((pow_rem(x , n // 2) ** 2) * x) % d

def solve():
    m, n = map(int, input().split())
    print(pow_rem(m, n))

solve()