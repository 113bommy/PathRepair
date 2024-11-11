N, K = list(map(int, input().split()))
mod = 10**9+7
ans = [0]*(K+1)
s = 0
for i in range(K, 0, -1):
    ans[i] = pow(K//i, N, mod)
    for j in range(2*i, K+1, i):
        ans[i] -= ans[j]
    s += ans[i]*i%mod
print(s%mod)
