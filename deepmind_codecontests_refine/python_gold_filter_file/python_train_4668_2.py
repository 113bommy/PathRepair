import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")



s = input()
K = int(input())
n = len(s)
dp = [[[0]*(K+1) for _ in range(n+2-i)] for i in range(n+1)]
for i in range(n):
    for j in range(K+1):
        dp[i][1][j] = 1
for l in range(2, n+1):
    for i in range(n-l+1):
        for k in range(K+1):
#             print(l, i, i+l, j)
            if s[i]==s[i+l-1]:
                dp[i][l][k] = dp[i+1][l-2][k] + 2
            else:
                dp[i][l][k] = max(dp[i+1][l-1][k], dp[i][l-1][k])
                if k>=1:
                    dp[i][l][k] = max(dp[i][l][k], dp[i+1][l-2][k-1]+2)
ans = max(dp[0][i][j] for i in range(n+2) for j in range(K+1))
print(ans)