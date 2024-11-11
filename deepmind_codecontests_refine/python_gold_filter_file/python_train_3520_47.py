def main():
    N = int(input())
    a = list(map(int, input().split()))

    dp = [[10**13]*N for i in range(N)]
    s = [0] * (N+1)
    for i in range(N):
        s[i+1] = s[i] + a[i]
        dp[i][i] = 0
    for i in range(N-1, -1, -1):
        for j in range(i+1, N):
            tmp = s[j+1] - s[i]
            for k in range(i, j):
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j] + tmp)

    print(dp[0][N-1])


main()
