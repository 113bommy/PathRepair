N, S=list(map(int,input().split()))
A=list(map(int,input().split()))
A=[0]+A
dp=[[0 for j in range(S+1)] for i in range(N+1)]
dp[0][0]=1
for i in range(1,N+1):
    for j in range(S+1):
        dp[i][j]=(dp[i][j]+2*dp[i-1][j]) %998244353 # x[i]を入れないが、大きい方に入れるか入れないかが二通り
    for j in range(S-A[i]+1):
        dp[i][j+A[i]]=(dp[i][j+A[i]]+dp[i-1][j]) %998244353 # x[i]を入れる
print(dp[N][S])