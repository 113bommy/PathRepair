# coding: utf-8
N,S=map(int,input().split())
A=list(map(int,input().split()))
MOD=998244353

dp=[[0 for j in range(S+1)] for i in range(N+1)]

dp[0][0]=1

for i in range(1,N+1):
    a=A[i-1]
    for j in range(0,S+1):
        dp[i][j]+=dp[i-1][j]*2
        if j-a>=0:
            dp[i][j]+=dp[i-1][j-a]
        dp[i][j]=dp[i][j]%MOD


print(dp[N][S])