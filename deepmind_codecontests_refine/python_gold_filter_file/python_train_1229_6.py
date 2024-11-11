n, k = map(int, input().split())
a_s = list(map(int, input().split()))
dp = ["Second"] * (k + 1)
for i in range(k + 1):
    if dp[i] == "Second":
        for a in a_s:
            ii = i + a
            if ii <= k:
                dp[ii] = "First"
print(dp[-1])
