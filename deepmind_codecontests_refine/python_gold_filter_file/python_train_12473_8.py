n = int(input())
h = list(map(int,input().split()))
dp = [0]*n
dp[1] = abs(h[0]-h[1])
for i in range(2,n):
    dp[i] = min(dp[i-2]+abs(h[i-2]-h[i]), dp[i-1]+abs(h[i-1]-h[i]))
print(dp[n-1])