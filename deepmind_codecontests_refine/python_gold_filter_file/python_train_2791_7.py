n,k = map(int,input().split())
h = list(map(int,input().split()))
dp = [10000000000]*n
dp[0] = 0
for i in range(n-1):
    for j in range(1,min(k+1,n-i)):
        dp[i+j] = min(dp[i+j],dp[i]+abs(h[i+j]-h[i]))
print(dp[n-1])
