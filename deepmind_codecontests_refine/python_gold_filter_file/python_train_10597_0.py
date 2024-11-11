n,m = map(int,input().split())
dp = [float("inf")]*(1<<n)
dp[0]=0
kagi = []
for i in range(m):
    a,b = map(int,input().split())
    c = list(map(int,input().split()))
    kagi.append([a,b,c])
for j in range(m):
    for i in range(1<<n):
        tmp = i+0
        for k in kagi[j][2]:
            tmp = tmp | 1<<(k-1)
        dp[tmp] = min(dp[tmp],dp[i]+kagi[j][0])
print(dp[(1<<n)-1] if dp[(1<<n)-1] != float("inf") else -1)