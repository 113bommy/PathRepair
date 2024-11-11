n, b = map(int, input().split(' '))

def factor(b):
    fac = {}
    for i in range(2, int(b**0.5) +1):
        if b % i == 0:
            fac[i] = 0
        while b % i == 0:
            fac[i] += 1
            b = b // i
        if b == 1: break
    if b > 1:
        if b not in fac:
            fac[b] = 0
        fac[b] += 1
    return fac


m = factor(b)
ans = 111111111111111111111
for k in m.keys():
    denom = k
    exp = 0
    while n // denom > 0:
        exp += n // denom
        denom *= k
    ans = min(ans, exp // m[k])

print(ans)
