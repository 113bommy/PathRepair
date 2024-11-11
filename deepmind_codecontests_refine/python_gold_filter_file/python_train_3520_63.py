mod = 10**9+7
N = int(input())
a = list(map(int, input().split()))
S = [0]*(N+1)#i~j-1の和はS[j]-S[i]
for i in range(1, N+1):
    S[i] = S[i-1]+a[i-1]
memo = [[-1]*(N+1) for _ in range(N)]
def dp(i, j):
    if memo[i][j]>=0:
        return memo[i][j]
    if j-i == 1:
        memo[i][j] = 0
        return 0
    memo[i][j] = min(dp(i, k)+dp(k, j)+S[j]-S[i]for k in range(i+1, j))
    return memo[i][j]
print(dp(0, N))


    






