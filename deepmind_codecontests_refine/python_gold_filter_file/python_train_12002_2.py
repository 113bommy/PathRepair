from sys import stdin, stdout

# 3 4 3
# 1 2 3 4
# 5 2 2 2
# 7 1 1 4
#
# 5 5 4
# 1 2 4 2 1     1 1 2 2 4
# 3 5 1 2 4     1 2 3 4 5
# 1 5 7 1 2     1 1 2 5 7
# 3 8 7 1 2     1 2 3 7 8
# 8 4 7 1 6     1 4 6 7 8
#
# 4 + 2 + 5 + 4 + 5 + 7 + 8 + 7 + 8 + 7
# 6 9  12  15  15
# 57 % 4 = 1
def zero_remainder_sum(n, m, k, a_a):

    # dp[n, m, cnt, k]
    cnt = m // 2
    dp = [[[-1 for _ in range(k)] for _ in range(cnt+1)] for _ in range(n)]
    dp[0][0][0] = 0

    for i in range(n):
        for j in range(m):
            #for c in range(1, cnt+1):
            #for c in range(1, min(cnt + 1, j + 2)):
            for c in range(min(m // 2 + 1, j + 2) - 1, 0, -1):
                for r in range(k):
                    if dp[i][c-1][r] == -1:
                        continue

                    v = dp[i][c-1][r] + a_a[i][j]
                    dp[i][c][v%k] = max(dp[i][c][v%k], v)
        if i != n-1:
            for c in range(0, cnt+1):
                for r in range(k):
                    dp[i+1][0][r] = max(dp[i+1][0][r], dp[i][c][r])

    res = 0
    for i in range(cnt+1):
        res = max(res, dp[n-1][i][0])

    return res


n, m, k = map(int, stdin.readline().split())
a_a = []
for _ in range(n):
    a_a.append(list(map(int, stdin.readline().split())))
res = zero_remainder_sum(n, m, k, a_a)
stdout.write(str(res))
