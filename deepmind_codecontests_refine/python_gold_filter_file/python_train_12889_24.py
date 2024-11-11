N, W = map(int,input().strip().split(" "))
Vmax = 10**5
dp = [10**9+1] * (Vmax+1)
dp[0] = 0
Vtotal = 0

for _ in range(N):
    w, v = map(int, input().strip().split(" "))
    Vtotal += v
    for i in range(Vtotal-v, -1, -1):
        dp[i+v] = min(dp[i+v], dp[i]+w)

for v in range(Vtotal, -1, -1):
    if dp[v] <= W:
        print(v)
        break
