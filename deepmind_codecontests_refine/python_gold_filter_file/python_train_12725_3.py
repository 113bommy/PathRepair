MOD = 998244353

def matrix_mul(a, b):
    return [[
        (a[0][0] * b[0][0] % MOD + a[0][1] * b[1][0] % MOD) % MOD,
        (a[0][0] * b[0][1] % MOD + a[0][1] * b[1][1] % MOD) % MOD
    ], [
        (a[1][0] * b[0][0] % MOD + a[1][1] * b[1][0] % MOD) % MOD,
        (a[1][0] * b[0][1] % MOD + a[1][1] * b[1][1] % MOD) % MOD
    ]]

def pow(p, a, b):
    t = [[a, b], [a, b]]
    m = [[a, b], [b, a]]
    while p:
        if p % 2:
            t = matrix_mul(t, m)
        m = matrix_mul(m, m)
        p //= 2
    return t

def fib(n, a, b):
    return pow(n, a, b)[0][0]

def pow_num(x, p):
    m = x
    t = 1
    while p:
        if p % 2:
            t *= m
            t %= MOD
        m *= m
        m %= MOD
        p //= 2
    return t

n, m, L, R = map(int, input().split())

a = 0
b = 0
if (R - L) % 2 == 1:
    a = (R - L + 1) // 2
else:
    if R % 2 == 1:
        a = (R - L + 1) // 2
    else:
        a = (R - L + 1) // 2 + 1
b = (R - L + 1 - a)

if (n * m % 2 == 0):
    print(fib(n * m - 1, a, b))
else:
    print(pow_num(R - L + 1, n * m))



    