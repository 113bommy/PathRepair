H, W, A, B = map(int, input().split())
INF = 10**9 + 7

def powmod(a, n, mod):
    p = 1
    while n > 0:
        if n % 2 == 0:
            a = a**2 % mod
            n /= 2
        else:
            p *= a
            p %= mod
            n -= 1
    return p


def invmod(a, mod):
    return powmod(a, mod-2, mod)


def combmod(n, k, mod):
    if n < k : return 0
    else:
        if n < 2*k: k = n-k
        bunsi = fac[n]
        bunbo = inv[k] * inv[n-k]
        return bunsi * bunbo % mod

fac = [1] * (H+W+1)
inv = [1] * (H+W+1)
for i in range(H+W+1):
    if i == 0:
        fac[i] = 1
        inv[i] = 1
    else:
        fac[i] = fac[i-1] * i % INF
        inv[i] = inv[i-1] * invmod(i, INF) % INF

ans = 0
for i in range(min(W, H - A + B) - B):
    h = H - A - i
    w = B + 1 + i
    ans += combmod(h+w-2, h-1, INF) * combmod(H+W-h-w, H - h, INF) % INF

print(ans%INF)