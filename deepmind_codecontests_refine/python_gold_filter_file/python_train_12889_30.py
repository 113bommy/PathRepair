# temp
n,w = map(int,input().split())
wv = [tuple(map(int,input().split())) for i in range(n)]

dp = [0] + [float("inf")]*(10**5)
for i in range(n):
    for j in range(10**5,wv[i][1]-1,-1):
        dp[j] = min(dp[j],dp[j-wv[i][1]]+wv[i][0])

res = 0
for v,e in enumerate(dp):
    if e <= w:
        res = v
print(res)