N, M = map(int, input().split())
MOD = 998244353

if N < M :
    one = N - (N - M) % 2
    two = (3 * M - one) // 2
else :
    one, two = M, M
    
L = M + M // 2 + N - 1

fac = [0] * (L + 1)
inv = [0] * (L + 1)
fac[0], inv[0] = 1, 1

for i in range(1, L + 1) :
    fac[i] = fac[i-1] * i % MOD
    inv[i] = pow(fac[i], MOD-2, MOD)

def comb(n, r) :
    if n <= 0 or r < 0 :
        return 0
    return fac[n]*inv[n-r]*inv[r]%MOD

ret = 0
while one >= 0 :
    ret += comb(N, one) * comb(two+N-1, N-1) % MOD
    ret %= MOD
    one -= 2
    two += 1
 
ret -= comb(3*M+N-1-(2*M+1), N-1) * N
print(ret % MOD)