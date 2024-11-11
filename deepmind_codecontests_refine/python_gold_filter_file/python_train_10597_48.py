n,m = map(int,input().split())
a_list = []
c = []

for i in range(m):
    a,b = map(int,input().split())
    a_list.append(a)
    c.append(sum(1 << j-1 for j in list(map(int,input().split()))))

inf = 10**10
dp = [inf]*(1 << n)
dp[0] = 0

for i in range(1 << n):
    for j in range(m):
        dp[c[j]|i] = min(dp[c[j]|i],dp[i]+a_list[j])

if dp[-1] == inf:
    print(-1)
else:
    print(dp[-1])