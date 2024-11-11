N, P = map(int, input().split())

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

fct = factorize(P)
fct.sort(key=lambda x:x[1], reverse=True)
res = 1
for el in fct:
    if el[1] >= N:
        res = res * el[0] ** (el[1] // N)

print(res)