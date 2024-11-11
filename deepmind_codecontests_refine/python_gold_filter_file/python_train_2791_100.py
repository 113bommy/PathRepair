n,k=map(int,input().split())
dp=[10**10]*n
h=list(map(int,input().split()))
dp[0]=0
for i in range(1,n):
    dp[i]=min(dp[i-j]+abs(h[i-j]-h[i]) for j in range(1,1+min(k,i)))

print(dp[-1])