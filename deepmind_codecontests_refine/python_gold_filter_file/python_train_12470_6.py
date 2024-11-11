from bisect import bisect_right
import sys
sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline


n, t = map(int, input().split())

shop = []
shop_a0 = []

for i in range(n):
    a, b = map(int, input().split())
    if a != 0:
        shop.append([a, b, a/(b+1)])
    else:
        shop_a0.append(b)

shop = sorted(shop, key=lambda x: -x[2])
shop_a0 = sorted(shop_a0)

n = len(shop)

INF = 10**10
dp = [INF for _ in range(30)]
dp[0] = 0

m = min(n+1, 30)

for i in range(n):
    for j in range(m)[::-1]:
        dp[j] = min(dp[j], dp[j-1] + 1 +
                         shop[i][0]*(dp[j-1]+1) + shop[i][1])

ss = []
if shop_a0:
    ss.append(1+shop_a0[0])
    for i in range(1, len(shop_a0)):
        ss.append(ss[-1]+1+shop_a0[i])

ans = 0

for i in range(m):
    if t - dp[i] >= 0:
        ans = max(ans, bisect_right(ss, t-dp[i]) + i)

print(ans)
