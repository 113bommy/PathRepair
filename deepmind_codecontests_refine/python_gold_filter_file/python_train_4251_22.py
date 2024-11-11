from math import factorial

N, M = map(int, input().split())
mod = 10 ** 9 + 7


def comb(n,r):
  if n >= r:
    numer = factorial(n) % mod
    denom_inv = pow(((factorial(r) % mod)* (factorial(n-r) % mod)), mod-2, mod)
    return (numer * denom_inv) % mod
  else:
    return 0


pp = [0]
div = 2
while M > 1:
    if pp[-1] != 0:
        pp.append(0)
    while M % div == 0:
        pp[-1] += 1
        M = M / div
    div += 1

ans = 1
for p in pp:
    ans = (ans * comb(N+p-1, p)) % mod

print(ans)