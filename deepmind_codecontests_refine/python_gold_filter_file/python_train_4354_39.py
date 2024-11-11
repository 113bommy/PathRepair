import sys

read = sys.stdin.read
sys.setrecursionlimit(10 ** 7)


def solve():
    n, *a = map(int, read().split())
    a = tuple(a)
    dp = [0] * n ** 2

    for i in range(n):
        dp[i * n + i] = a[i]
    for i in range(n - 2, -1, -1):
        for j in range(i + 1, n):
            L = a[i] - dp[(i + 1) * n + j]
            R = a[j] - dp[i * n + j - 1]
            if L > R:
                dp[i * n + j] = L
            else:
                dp[i * n + j] = R
    return dp[n - 1]


print(solve())
