n = int(input())
v = list(map(int, input().split()))

mx = 1
dp = [0]*n
dp[0] = 1

for i in range(1, n):
    if v[i] > v[i-1]:
        dp[i] = dp[i-1]+1
    else:
        dp[i] = 1
    
    mx = max(dp[i], mx)

print(mx)