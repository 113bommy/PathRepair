# from bisect import bisect_left
TC = int(input())

for tc in range(TC):
    N = int(input())
    A = list(map(int, input().split()))
    # print(A)

    if N < 4:
        print(A[0])
    else:
        dp = [0 for _ in range(N)]

        dp[0] = A[0]
        dp[1] = dp[0]
        dp[2] = dp[0]
        dp[3] = dp[0] + min(A[1], A[2], A[3])
        # dp[4] = min(dp[3] + A[4], dp[2] + A[3] + 0, dp[1] + A[2] + A[3])

        for i in range(4, N):
            dp[i] = min(dp[i - 1] + A[i], dp[i - 2] + A[i - 1], dp[i - 3] + A[i - 2], dp[i - 4] + A[i - 3] + A[i - 2])

        print(dp[-1])
