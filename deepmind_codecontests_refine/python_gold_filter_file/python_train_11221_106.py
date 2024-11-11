H,N,*AB = map(int, open(0).read().split())
dp = [0]+[10**8]*H
for n in range(N):
  A,B = AB[2*n:2*(n+1)]
  for h in range(1,H+1): dp[h] = min(dp[h],dp[max(0,h-A)]+B)
print(dp[-1])