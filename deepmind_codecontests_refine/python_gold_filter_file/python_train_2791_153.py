N,K=map(int,input().split())
H=list(map(int,input().split()))
dp = [float("inf")]*N
dp[0]=0
for i in range(N-1):
    for j in range(1,min(K+1,N-i)):
        dp[i+j]=min(dp[i+j],dp[i]+abs(H[i+j]-H[i]))
print(dp[-1])