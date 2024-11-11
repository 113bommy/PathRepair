N=int(input())
a=list(map(int,input().split()))
dp=[[0]*(N+1) for i in range(N+1)]
#dp[a][b]でa:残っている数列の長さ b:左端
for w in range(1,N+1):
  for l in range(N-w+1):
    r=l+w
    dpl=-dp[l+1][r]+a[l]
    dpr=-dp[l][r-1]+a[r-1]
    dp[l][r]=max(dpl,dpr)
print(dp[0][N])