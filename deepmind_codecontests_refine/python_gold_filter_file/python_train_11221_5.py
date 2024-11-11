h,n= map(int, input().split())
p = [list(map(int, input().split())) for _ in range(n)] 
m = 10**4
dp = [0]*(h+m+1)
for i in range(m+1,h+m+1):
  dp[i] = min(dp[i-a] + b for a,b in p)
print(dp[h+m])