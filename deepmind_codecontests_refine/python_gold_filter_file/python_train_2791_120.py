N , K = map(int, input().split())
h = list(map(int, input().split()))

Dp = [None]*N
Dp[0] = 0

for i in range(1,N):
  Dp[i] =min([Dp[j]+abs(h[i]-h[j]) for j in range(max(0,i-K),i)])

print(Dp[-1])
