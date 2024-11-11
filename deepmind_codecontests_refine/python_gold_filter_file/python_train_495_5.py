n = int(input())
x = list(map(int, input().split()))

mod = 10**9 + 7

fac = [1, 1]
inv = [1, 1]
finv = [1, 1]
for i in range(2, n+5):
    fac.append(fac[i-1] * i % mod)
    inv.append(mod - inv[mod%i] * (mod//i) % mod)
    finv.append(finv[i-1] * inv[i] % mod)

ans = 0
j_inv = []
num = 0
for j in range(1, n):
    num += inv[j]
    num %= mod
    j_inv.append(num)

for i in range(n-1):
    ans += j_inv[i] * (x[i+1] - x[i])
    ans %= mod

ans *=fac[n-1]
ans %= mod

print(ans)

