n,p,t = input().split()
n = int(n)
p = float(p)
t = int(t)
# dp[n][p][t]
dp = [[0 for _ in range(t+1)] for _ in range(n+1)]
dp[0][0] = 1
for n_p in range(n+1):
    for t_p in range(t):
        dp[n_p][t_p+1] = dp[n_p][t_p]*(1-p) + dp[n_p][t_p+1]
        if n_p != n:
            dp[n_p+1][t_p+1] = dp[n_p][t_p]*p + dp[n_p+1][t_p+1]
        else:
            dp[n_p][t_p+1] = dp[n_p][t_p]*p + dp[n_p][t_p+1]
ans = 0
for n_p in range(n+1):
    ans += dp[n_p][-1] * n_p
# print(dp)
print(ans)