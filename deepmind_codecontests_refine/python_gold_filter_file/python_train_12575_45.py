N = int(input())
S = input()

ans = 0
dp = [0] * N
for i in range(N - 1):
    dp2 = dp[:]
    for j in range(i + 1, N):
        if S[i] == S[j] and j - i > dp2[j-1]:
            dp[j] = dp2[j-1] + 1
            ans = max(ans, dp[j])
        else:
            dp[j] = 0

print(ans)