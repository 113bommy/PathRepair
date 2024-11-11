def main():
    n, k = map(int, input().split())
    tmp = list(map(int, input().split()))
    h = [0]
    for v in tmp:
        h.append(v)
    dp = [[float("inf")]*(n-k+1) for i in range(n+1)]
    dp[0][0] = 0
    for i in range(1, n+1):
        for j in range(1, n-k+1):
            tmp = float("inf")
            for l in range(i):
                p = max(0, h[i] - h[l])
                if tmp > dp[l][j-1] + p:
                    tmp = dp[l][j-1] + p
            dp[i][j] = tmp
    ans = float("inf")
    for i in range(n+1):
        if ans > dp[i][n-k]:
            ans = dp[i][n-k]
    print(ans)

if __name__ == "__main__":
    main()