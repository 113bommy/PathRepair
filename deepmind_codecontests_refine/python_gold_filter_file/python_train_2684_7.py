fact = [1 for _ in range(200000)]
inv = [1 for _ in range(200000)]
fact_inv = [1 for _ in range(200000)]

mod = 998244353
for i in range(2, 200000):
    fact[i] = (fact[i-1]*i) % mod
    inv[i] = mod - (inv[mod % i] * (mod // i)) % mod
    fact_inv[i] = (fact_inv[i-1] * inv[i]) % mod

N, M, K = map(int, input().split())
ans = 0
a = pow(M-1, N-1-K, mod)
for i in range(K, -1, -1):
    ans += (fact[N-1] * fact_inv[i] * fact_inv[N-1-i]) * M * a
    ans = ans % mod
    a *= M-1
    a = a % mod
print(ans)