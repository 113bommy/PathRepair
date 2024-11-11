import sys
input = sys.stdin.readline

n, m = map(int, input().split())
dp = [float('inf')] * (2 ** n)
dp[0] = 0
for i in range(m):
    a, b = map(int, input().split())
    c = sum(1 << (i - 1) for i in map(int, input().split()))
    for j in range(2 ** n):
        if dp[c | j] > dp[j] + a:
            dp[c | j] = dp[j] + a

if dp[-1] == float('inf'):
    ans = -1
else:
    ans = dp[-1]
print(ans)
