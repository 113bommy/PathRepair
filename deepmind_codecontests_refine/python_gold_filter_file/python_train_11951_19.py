LI = lambda: list(map(int, input().split()))

N, K = LI()
H = LI()

INF = 10 ** 15


def main():
    h = [0] + H
    dp = [[INF] * (N + 1) for _ in range(N + 1)]
    dp[0][0] = 0
    for i in range(1, N + 1):
        for j in range(1, i + 1):
            v = INF
            for k in range(i):
                x = max(0, h[i] - h[k])
                v = min(v, dp[k][j - 1] + x)
            dp[i][j] = v

    ans = min([dp[i][N - K] for i in range(N - K, N + 1)])
    print(ans)


if __name__ == "__main__":
    main()
