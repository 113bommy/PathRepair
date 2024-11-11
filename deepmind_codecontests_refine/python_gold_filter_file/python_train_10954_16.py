from collections import defaultdict
n = int(input())
l = list(map(int , input().split()))

dp = [0] * n
dp2  = [0]*(10**6)

for i in range(1,n+1):
    dp[i-1] = l[i-1] - i

for i in range(n):
    dp2[dp[i]] += l[i]

print(max(dp2))

