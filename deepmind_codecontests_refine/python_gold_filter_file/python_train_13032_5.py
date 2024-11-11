def fast_pow(x, y, mod):
    if y == 0:
        return 1
    if y % 2 == 1:
        return (x * fast_pow(x, y - 1, mod)) % mod
    else:
        c = fast_pow(x, y // 2, mod)
        return (c * c) % mod


mod = 10 ** 9 + 7
x, n = map(int, input().split())
primes = []
div = 2
while div * div <= x:
    if x % div == 0:
        if len(primes) == 0 or primes[-1] != div:
            primes.append(div)
        x //= div
    else:
        div += 1
ans = 1
if len(primes) == 0 or primes[-1] != x:
    primes.append(x)
for p in primes:
    cnt = p
    degree = 0
    while n // cnt > 0:
        degree += n // cnt
        cnt *= p
    ans *= fast_pow(p, degree, mod)
    ans %= mod
print(ans)     