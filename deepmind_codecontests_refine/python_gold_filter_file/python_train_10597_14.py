n, m = map(int, input().split())
c = []
a = []
for _ in range(m):
    ai, bi = map(int, input().split())
    ci = list(map(lambda x: 2 ** (int(x) - 1) , input().split()))
    a.append(ai)
    c.append(sum(ci))

INF = 100 ** 18
dp = [INF] * (2**n)
dp[0] = 0
for i in range(m):
    for j in range(0, 2**n):
        dp[j | c[i]] = min(dp[j | c[i]], dp[j] + a[i])

ans = dp[2**n-1]
if ans == INF:
    print(-1)
    exit()
print(ans)

