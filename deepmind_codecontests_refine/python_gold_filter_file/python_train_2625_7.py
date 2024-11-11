a = []
dp = []

t = int(input())
for j in range(t):
    n, p, k = map(int, input().split())
    a = list(map(int, input().split()))
    dp = [0] * n
    a.sort()

    dp[0] = a[0]
    for i in range(1, n):
        if i < k-1:
            dp[i]=dp[i-1]+a[i]
        else:
            dp[i]=min(dp[i-k]+a[i], dp[i-1]+a[i])
    
    ans=-1
    for i in range(n):
        if dp[i] <= p:
            ans = i
    print(ans+1)