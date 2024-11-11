N, S = map(int, input().split())
A = list(map(int, input().split()))
MOD = 998244353

DP = [[0] * (S + 1) for i in range(N + 1)]
DP[0][0] = 1
for i in range(N):
  for j in range(S + 1):
    if j >= A[i]:
      DP[i + 1][j] = (DP[i][j] * 2 + DP[i][j - A[i]]) % MOD
    else:
      DP[i + 1][j] = (DP[i][j] * 2) % MOD

print(DP[-1][-1] % MOD)




