n,m = map(int, input().split())
l = []
for _ in range(m):
    a,b = map(int, input().split())
    cl = [x-1 for x in map(int, input().split())]
    b = 0
    for i in cl:
        b |= 1<<i
    l.append([a,b])

inf = 10**9
dp = [inf]*2**n
dp[0] = 0
for x in range(2**n):
    for i in range(m):
        a,b = l[i]
        dp[x|b] = min(dp[x|b], dp[x]+a)

if dp[-1]==inf:
    print(-1)
else:
    print(dp[-1])