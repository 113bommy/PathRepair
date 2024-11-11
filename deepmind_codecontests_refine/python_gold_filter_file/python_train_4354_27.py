N = int(input())
a_list = list(map(int, input().split()))

dp = [[0]*(N+10) for _ in range(N+10)]
dp[0][0] = 0
for width in range(1, N+1):
    for l in range(1, N+1):
        r = l + width
        if r >= N+2:
            break
        if width % 2 == N % 2:
            dp[l][r] = max(dp[l][r-1]+a_list[r-2], dp[l+1][r]+a_list[l-1])
        else:
            dp[l][r] = min(dp[l][r-1]-a_list[r-2], dp[l+1][r]-a_list[l-1])

print(dp[1][N+1])