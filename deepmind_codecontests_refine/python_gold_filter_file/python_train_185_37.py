def factorize(n):
    fct = []
    b, e = 2, 0
    while b * b <= n:
        while n % b == 0:
            n = n // b
            e = e + 1
        if e > 0:
            fct.append((b, e))
        b, e = b + 1, 0
    if n > 1:
        fct.append((n, 1))
    return fct

N,P = list(map(int, input().split()))
ans = 1
fct = factorize(P)
for f in fct:
    ans = ans * max(1,(f[0] ** (f[1]//N)))

print(ans)