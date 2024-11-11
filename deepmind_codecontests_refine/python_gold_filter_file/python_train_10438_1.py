R,G,B=map(int,input().split())
r=sorted(list(map(int,input().split())))
g=sorted(list(map(int,input().split())))
b=sorted(list(map(int,input().split())))
dp=[[[0]*(B+1) for j in range(G+1)] for i in range(R+1)]
for i in range(R+1):
    for j in range(G+1):
        for k in range(B+1):
            if i>0 and j>0:
                dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+r[i-1]*g[j-1])
            if i>0 and k>0:
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k-1] + r[i - 1] * b[k - 1])
            if j>0 and k>0:
                dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k - 1] + g[j - 1] * b[k - 1])
print(dp[R][G][B])








