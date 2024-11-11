n,k = [int(i) for i in input().split()]
h = [int(i) for i in input().split()]
inf = 10**10
dp = [inf]*n
dp[0] = 0
 
for i in range(1,n):
    dp[i] = min(dp[i-j]+abs(h[i]-h[i-j]) for j in range(min(i,k)+1))
 
print(dp[n-1])