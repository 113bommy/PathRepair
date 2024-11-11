N = int(input())
a = list(map(int, input().split()))

M = 10 ** 15
DP = [[0] * N for _ in range(N)]

if N % 2 == 0:
  t = -1
else:
  t = 1
for i in range(N):
  DP[0][i] = a[i] * t
t *= -1

for i in range(1, N):
  for j in range(N - i):
    if t > 0:
      DP[i][j] = max(DP[i - 1][j] + a[i + j], DP[i - 1][j + 1] + a[j])
    else:
      DP[i][j] = min(DP[i - 1][j] - a[i + j], DP[i - 1][j + 1] - a[j])
  t *= -1

print(DP[-1][0])