import sys
input = sys.stdin.readline

n, m = map(int, input().split())
mod = 998244353

if n == 2:
    print(0)
    exit()

max_n = 2*10**5 + 10
fac, inv = [1]*max_n, [0]*max_n
for i in range(2, max_n):
    fac[i] = fac[i-1] * i % mod
inv[-1] = pow(fac[-1], mod-2, mod)
for i in range(max_n-1, 0, -1):
    inv[i-1] = inv[i] * i % mod

ans = fac[m] * inv[n-1] * inv[m-n+1] * (n-2) * pow(2, n-3, mod) % mod
print(ans)
