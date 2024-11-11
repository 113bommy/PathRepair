def prime_factor(n):
    ret = {}
    p = 2
    while p*p <= n:
        while n % p == 0:
            ret[p] = ret.get(p, 0) + 1
            n //= p
        p += 1
    if n != 1: ret[n] = 1
    return ret

n, p = map(int, input().split())

primes = prime_factor(p)
ans = 1

for p, e in primes.items():
    ans *= max(1, p**(e//n))

print(ans)
