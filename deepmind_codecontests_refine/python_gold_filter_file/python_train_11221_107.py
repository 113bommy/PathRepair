(h, n), *m = [[*map(int, i.split())] for i in open(0)]
dp = [0] + [10**9] * h
for i in range(1, h + 1):
    for a, b in m:
        dp[i] = min(dp[i], dp[max(i-a,0)]+b)
print(dp[-1])
