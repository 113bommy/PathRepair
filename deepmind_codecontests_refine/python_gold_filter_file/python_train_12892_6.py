n = int(input())
s1 = input()
s2 = input()
mod = 10**9+7
dp = [-1] * (n)
if s1[0] == s2[0]:
    dp[0] = 1 
else:
    dp[0] = 2
for i in range(n-1):
    if dp[i] == -1:
        continue
    if s1[i] == s2[i]:
        dp[i+1] = (dp[i] * 2) % mod
        continue
    if i+2 >= n:
        break
    if s1[i+2] == s2[i+2]:
        dp[i+2] = dp[i]
    else:
        dp[i+2] = (dp[i] * 3) % mod

ans = dp[-1] if dp[-1] != -1 else dp[-2]
print((ans * 3) % mod)
# print(dp)