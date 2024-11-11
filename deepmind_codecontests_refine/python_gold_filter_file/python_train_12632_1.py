n = int(input())
dp = [0 for _ in range(n+1)]
pre = [0 for _ in range(2001)]
for i in range(1,n+1):
    s = input().split()
    dp[i] = dp[i-1]
    t = int(s[1])
    if s[0][0] == 'w':
        pre[t] = i
    else:
        if pre[t]:
            ans = dp[pre[t]] + (1<<t)
            if ans > dp[i]:
                dp[i] = ans
print (dp[n])