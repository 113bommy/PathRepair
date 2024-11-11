N = int(input())
A = list(map(int, input().split()))


def solve(N,A):
    s,e = 0, N-1
    dp = [[0]*N for i in range(N)]
    for k in range(N):
        for i in range(N):
            j = i+k
            if j>=N:
                continue
            sign = (-1)**(N-1-k)
            if k==0:
                dp[i][j] = sign*A[i]
                continue
            dp[i][j] = sign*max(sign*dp[i+1][j]+A[i],sign*dp[i][j-1]+A[j])
    ans = dp[0][N-1]
    return ans
print(solve(N,A))