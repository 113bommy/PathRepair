N, S = map(int,input().split())
A = list(map(int,input().split()))
mod = 998244353
dp = [0 for j in range(S + 1)]
dp[0] = 1
for i in range(N) : 
    for j in range(S, -1, -1) : 
        if j + A[i] <= S : 
            dp[j + A[i]] += dp[j]
            dp[j + A[i]] %= mod
        dp[j] *= 2
        dp[j] %= mod 
        
print(dp[S])
