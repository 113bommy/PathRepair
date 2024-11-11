def solve(N, Q, intervals):
    # dp[i]: most painted sections at j-th section
    dp = [0] * (N + 1)

    # leftmost idx that cover i-th section
    L = [i + 1 for i in range(N + 1)]
    for l, r in intervals:
        for i in range(l, r + 1, 1):
            L[i] = min(L[i], l)

    for _ in range(Q - 2):
        for i in range(N, 0, -1):
            l = L[i]
            dp[i] = max(
                dp[i],
                dp[l - 1] + i - l + 1
            )

        for i in range(1, N + 1, 1):
            dp[i] = max(dp[i], dp[i - 1])

    return dp[N]

N, Q = map(int, input().split())
intervals = []
for _ in range(Q):
    l, r = map(int, input().split())
    intervals.append((l, r))

print(solve(N, Q, intervals))
