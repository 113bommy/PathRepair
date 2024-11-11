# E - Colorful Blocks

MOD = 998244353
N, M, K = map(int, input().split())

# 予め階乗を計算しておく
f = [1]
for i in range(N):
    f.append(f[i]*(i+1)%MOD)

# 組み合わせ関数
def comb_mod(n, r, p):
    return f[n] * pow(f[r], p-2, p) * pow(f[n-r], p-2, p)

ans = 0
for i in range(K+1):
    ans = (ans + (M*pow(M-1, N-1-i,MOD)) * comb_mod(N-1, i, MOD))%MOD

print(ans)
