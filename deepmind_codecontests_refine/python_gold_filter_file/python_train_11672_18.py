N, M, K, L = map(int, input().split())
k = (M + L + K - 1) // M
if M * k <= N:
  print(k)
else:
  print(-1)