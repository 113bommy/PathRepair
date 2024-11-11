h, w, k = map(int, input().split())
a = [0]*(w-1) + [0,1]
for i in range(w-1):
    a[i] = a[i-1] + a[i-2]
dp = [0]*(w+1)
tmp = [0]*(w+1)
dp[0] = 1
for _ in range(1, h+1):
    for i in range(w):
        tmp[i] = (dp[i]*a[i-1]*a[w-i-2]
            + dp[i+1]*a[i-1]*a[w-i-3]
            + dp[i-1]*a[i-2]*a[w-i-2]) % (10**9+7)
    dp, tmp = tmp, dp
print(dp[k-1])
