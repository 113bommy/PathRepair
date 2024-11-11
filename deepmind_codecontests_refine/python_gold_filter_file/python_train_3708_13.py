s = input()
inf = 1e30
s = [int(x) for x in s.split()]
n = s[0]
p = s[1]
q = s[2]
r = s[3]
a = input()
a = [int(x) for x in a.split()]
dp = []
for i in range(n+1):
    dp.append(0)
dp[0] = -inf
i = 1
while i<=n : 
    now = p * a[i-1]
    dp[i] = max(dp[i-1],now)
    i = i+1
i=1
while i<=n : 
    now = q * a[i-1]
    dp[i] = max(dp[i-1],dp[i] + now)
    i = i+1
i = 1
ans = -inf
while i<=n:
    now = r * a[i-1]
    dp[i] = max(dp[i-1],dp[i] + now)
    ans = max(ans,dp[i])
    i = i+1
print (ans)

            
            
        
