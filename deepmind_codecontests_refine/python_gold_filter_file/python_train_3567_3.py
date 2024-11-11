from sys import stdin, stdout


# case 1: r1*a + r3
# case 2: r2 + [r1]
# case 3: r1*(a+1) + [r1]
def monster_invaders(n, r1, r2, r3, d, a_a):
    dp = [[10 ** 18, 10 ** 18] for _ in range(n)]
    dp[0][0] = r1 * a_a[0] + r3
    dp[0][1] = min(r2, r1 * (a_a[0] + 1))

    for i in range(1, n):
        # 0 -> 0
        dp[i][0] = min(dp[i][0], dp[i-1][0] + d + r1 * a_a[i] + r3)

        # 1 -> 0
        # 1 -> (0) -> 0 -> (0)
        dp[i][0] = min(dp[i][0], dp[i-1][1] + d + (r1 * a_a[i] + r3) + d + r1 + d)
        # 1 -> (1) -> 0 -> (0)
        dp[i][0] = min(dp[i][0], dp[i-1][1] + d + min(r2, r1 * (a_a[i] + 1)) + d + r1 + d + r1)

        # 0 -> 1
        dp[i][1] = min(dp[i][1], dp[i-1][0] + d + min(r2, r1 * (a_a[i] + 1)))

        # 1 -> 1
        # 1 -> (a) -> 0 -> (1)
        dp[i][1] = min(dp[i][1], dp[i-1][1] + d + d + r1 + d + min(r2, r1 * (a_a[i] + 1)))

        if i == n - 1:
            dp[i][0] = min(dp[i][0], dp[i-1][1] + d + (r1 * a_a[i] + r3) + d + r1)

    return dp[n-1][0]


def monster_invaders2(n, r1, r2, r3, d, a_a):
    dp = [[10 ** 18, 10 ** 18] for _ in range(2)]
    dp[0][0] = r1 * a_a[0] + r3
    dp[0][1] = min(r2, r1 * (a_a[0] + 1))

    i = 1
    for j in range(1, n):
        # 0 -> 0
        dp[i][0] = min(dp[i][0], dp[i-1][0] + d + r1 * a_a[j] + r3)

        # 1 -> 0
        # 1 -> (0) -> 0 -> (0)
        dp[i][0] = min(dp[i][0], dp[i-1][1] + d + (r1 * a_a[j] + r3) + d + r1 + d)
        # 1 -> (1) -> 0 -> (0)
        dp[i][0] = min(dp[i][0], dp[i-1][1] + d + min(r2, r1 * (a_a[j] + 1)) + d + r1 + d + r1)

        # 0 -> 1
        dp[i][1] = min(dp[i][1], dp[i-1][0] + d + min(r2, r1 * (a_a[j] + 1)))

        # 1 -> 1
        # 1 -> (a) -> 0 -> (1)
        dp[i][1] = min(dp[i][1], dp[i-1][1] + d + d + r1 + d + min(r2, r1 * (a_a[j] + 1)))

        if j == n - 1:
            dp[i][0] = min(dp[i][0], dp[i-1][1] + d + (r1 * a_a[j] + r3) + d + r1)

        dp[0] = dp[1]
        dp[1] = [10 ** 18, 10 ** 18]

    return dp[0][0]


n, r1, r2, r3, d = map(int, stdin.readline().split())
a_a = list(map(int, stdin.readline().split()))
#ans = monster_invaders(n, r1, r2, r3, d, a_a)
ans = monster_invaders2(n, r1, r2, r3, d, a_a)
stdout.write(str(ans) + '\n')
