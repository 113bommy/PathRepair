h,n = map(int,input().split())
a = [0]*n
for i in range(n):
    a[i] = list(map(int,input().split()))
dp = [float("Inf")]*(h+1)
dp[0] = 0
for i in range(h):
    for A,B in a:
        dp[min(i+A,h)] = min(dp[min(i+A,h)],dp[i]+B)
print(dp[-1])