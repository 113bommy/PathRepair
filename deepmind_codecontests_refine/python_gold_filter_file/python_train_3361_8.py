INF = 0x3f3f3f3f3f3f3f3f
q = int(input())
for _ in range(q):
    n = int(input())
    t = [0] + list(map(int, input().split()))
    t.sort()
    m = n*2
    dp = [ [0]*(m+1) ] + [ [INF]*(m+1) for _ in range(n) ]
    for i in range(1, n+1):
        for j in range(1, m+1):
            # print(f"dp[{i}][{j}] = min({dp[i][j]}, {dp[i][j-1]}, {dp[i-1][j-1]+abs(j-t[i])})")
            dp[i][j] = min(dp[i][j], dp[i][j-1], dp[i-1][j-1]+abs(j-t[i]))
    print(dp[n][m])
