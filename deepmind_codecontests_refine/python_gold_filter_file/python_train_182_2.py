N = [0] + list(map(int, input()))
K = int(input())
n = len(N)

DP = [
      [[0] * (K+2) for _ in range(2)] for _ in range(n)
]

# 0桁目(0)で最大値を取っていてk=0の要素は1個。
DP[0][0][0] = 1

for i in range(1, n):
  for k in range(K+1):
    if N[i] != 0:
      DP[i][0][k+1] += DP[i-1][0][k]
      DP[i][1][k] += DP[i-1][0][k]
      DP[i][1][k+1] += DP[i-1][0][k] * (N[i] - 1)
    else:
      DP[i][0][k] += DP[i-1][0][k]
    DP[i][1][k] += DP[i-1][1][k]
    DP[i][1][k+1] += DP[i-1][1][k] * 9
print(DP[n-1][1][K] + DP[n-1][0][K])