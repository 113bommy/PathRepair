def main():
    N = int(input())
    A = list(map(int, input().split()))
    dp = [[0] * (len(A) - i) for i in range(len(A))]

    for i in range(1, len(A)):
        s = sum(A[:i])
        for j in range(len(A) - i):
            s += A[i + j]
            dp[i][j] = min(dp[k][j] + dp[i - k - 1][j + k + 1] for k in range(i)) + s
            s -= A[j]
    print(dp[-1][0])


main()
