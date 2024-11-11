s = input()
t = input()
S = (len(s)+1)
T = (len(t)+1)

dp = [[0]*T for i in range(S)]

for i in range(1, S):
   for j in range(1, T):
       dp[i][j] = max(dp[i-1][j], dp[i][j-1])
       if s[i-1] == t[j-1]:
           dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1)

# print(dp[len(s)][len(t)])

ans = ""
i = len(s)
j = len(t)
while i > 0 and j > 0:
    if dp[i][j] == dp[i-1][j]:
        i -= 1
    elif dp[i][j] == dp[i][j-1]:
        j -= 1
    else:
        ans += s[i-1]
        i -= 1
        j -= 1
    
print(ans[::-1])
