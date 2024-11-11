N, M = map(int, input().split())

C = []
dp = [10 ** 9 for i in range (1 << N)]
dp [0] = 0
for i in range(M):
  a, b = map(int, input().split())
  c = list(map(lambda x: int(x) - 1, input().split()))
  b = 0
  for i in c:
    b |= 1 << i
  C.append((b,a))
for s in range(1 << N):
  for c in range(M):
    t = s | C[c][0]
    dp[t] = min(dp[t], dp[s] + C[c][1])
print (dp[-1] if dp[-1] != 10 ** 9 else -1)