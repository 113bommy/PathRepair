import sys, math
def fact(n):
    res = 1
    for i in range(1, n + 1):
        res = ((res % mod) * (i % mod)) % mod
    return res

def pow(a,b):
    res = 1
    while b:
        if b % 2:
            res = (res * a) % mod
        a = (a * a) % mod
        b //= 2
    return res

mod = 1000000007
n = int(sys.stdin.readline())
print((fact(n) - pow(2, n - 1)) % mod)