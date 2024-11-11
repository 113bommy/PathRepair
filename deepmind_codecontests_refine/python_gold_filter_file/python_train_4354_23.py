import sys
input = sys.stdin.readline

N = int(input())
a = list(map(int, input().split()))
dp = [[0] * N for _ in range(N)]

for l in range(N):
    for i in range(N-l):
        if l == 0:
            dp[i][i] = a[i]
        else:
            j = i + l
            dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1])
print(dp[0][N-1])