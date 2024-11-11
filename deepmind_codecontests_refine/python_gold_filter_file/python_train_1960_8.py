K, N = map(int, input().split())
mod = 998244353


def cmb(n, r, mod):
    if (r < 0 or r > n):
        return 0
    r = min(r, n-r)
    return g1[n] * g2[r] * g2[n-r] % mod


def H(n, k, mod):
    return cmb(n+k-1, k, mod)

Nmax = 10**5
g1 = [1, 1]
g2 = [1, 1]
inv = [0, 1]

for i in range(2, Nmax+1):
    g1.append((g1[-1] * i) % mod)
    inv.append((-inv[mod % i] * (mod//i)) % mod)
    g2.append((g2[-1] * inv[-1]) % mod)

ans = []
for i in range(2, K+2):
    res = 0
    if i % 2 == 1:
        for j in range(i//2+1):
            res += cmb(i//2, j, mod)*2**j*H(K-i//2*2+j, N-j, mod)
            res %= mod
    else:
        for j in range(i//2):
            res += cmb(i//2-1, j, mod)*2**j*H(K-i+1+j, N-j, mod)
            res += cmb(i//2-1, j, mod)*2**j*H(K-i+1+j, N-1-j, mod)
            res %= mod
    ans.append(res)

for elem in ans + ans[-2::-1]:
    print(elem)
