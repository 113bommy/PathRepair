def resolve():
    N = int(input())
    A = list(map(int, input().split()))
    cum_A = [0]*(N+1)
    for i in range(N):
        cum_A[i+1] = cum_A[i] + A[i]

    dp = [[1<<60]*(N+1) for _ in range(N+1)]
    for i in range(N+1):
        dp[i][i] = 0

    for l in range(2, N+1):
        # right = left + len - 1でrightが[0, N - 1]のように
        for left in range(N-l+1):
            right = left + l-1
            #if right>= N: continue
            cost = cum_A[right+1] - cum_A[left]
            for k in range(left, right):
                tmp = dp[left][k] + dp[k+1][right] + cost
                dp[left][right] = min(dp[left][right], tmp)

    return print(dp[0][N-1])

if __name__ == "__main__":
    resolve()