def main():
    n = int(input())
    a = tuple(map(int, input().split()))
    dp = [[0] * (n + 1) for _ in range(n+1)]

    for len in range(1, n + 1):
        for i in range(0, n - len + 1):
            j = i + len
            if (n - len) % 2 == 0:
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1])
            else:
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1])
    print(dp[0][n])


if __name__ == '__main__':
    main()
