ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))

n,K = mi()
hlis = li()

inf = 10 **13 + 7
dp = [[inf]*n for _ in range(n)]
for i in range(n):
    dp[0][i] = hlis[i]

for i in range(1,n):
    for k in range(i,n):
        #dp[i][k] = min(dp[i][k],dp[i-1][l] + abs)
        for l in range(k):
            dp[i][k] = min(dp[i][k],dp[i-1][l] + max(0,hlis[k] - hlis[l]))

tukau = n - K
ans = inf
if K == n:
    print(0)
    exit()
for i in range(tukau-1,n):
    ans = min(ans,dp[tukau-1][i])
print(ans)

