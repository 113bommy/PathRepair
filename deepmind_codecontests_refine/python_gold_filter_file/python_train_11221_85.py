H,N = map(int,input().split())
AB = [list(map(int,input().split())) for _ in range(N)]

dp = [float("inf") for _ in range(H+1)]

dp[H] = 0

for a,b in AB:
    for h in range(H,0,-1):
        i = max(0,h-a)
        dp[i] = min(dp[i],dp[h]+b)
print(dp[0])