n,a,b,c = map(int, input().split())
kus=0
if a>b:
    a,b=b,a
if b>c:
    b,c=c,b
if a>b:
    a,b=b,a
k=n+c+1
dp=[0]*k
dp.append(1)
dp.reverse()
for i in range(n):
    if ((dp[i]+1)>dp[i+a]) and (dp[i]!=0) :
        dp[i+a]=dp[i]+1
    if (dp[i]+1)>dp[i+b] and (dp[i]!=0):
        dp[i+b]=dp[i]+1
    if (dp[i]+1)>dp[i+c] and (dp[i]!=0):
        dp[i+c]=dp[i]+1
print(dp[n]-1)