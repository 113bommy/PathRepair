N, M, K = map(int, input().split())

mod = 998244353
f = [1]
for i in range(1,N+1):
    f.append((f[-1] * i) % mod)
def comb(n,r):
    return f[n] * (pow(f[r], mod-2, mod) * pow(f[n-r], mod-2, mod) % mod) % mod

ans = 0

for i in range(K+1):
    k = ((M * pow((M-1), N-1-i, mod)) % mod) * comb(N-1,i)
    k %= mod
    ans += k
    ans %= mod
    
print(ans)
    
    
    
