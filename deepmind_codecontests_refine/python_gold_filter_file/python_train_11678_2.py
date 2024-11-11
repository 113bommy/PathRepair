base = 1000000007
n , m , k = map(int,input().split())
a = list(map(int,input().split()))
mx = 0
s = 0
dp = []
dd= []
for j in range(m):
    for i in range(n+1):
        dp.append(base)
        dd.append(0)
    for i in range(n):
        dd[i+1]=dd[i]+a[i]-k*(i % m== j)
        dp[i+1] = min(dd[i],dp[i])
        #print(dd)
        #print(dp)
        if (i % m == j):
            mx = max ( mx , dd[i+1]-dp[i+1])
print(mx)