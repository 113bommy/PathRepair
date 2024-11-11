N=int(input())
dp=[[0]*3 for i in range(N+1)]#今回は正の範囲で最大値をもとめたいので0で初期化
for i in range(N):
  a=list(map(int,input().split()))
  for j in range(3):
    for k in range(3):
      if k!=j:
        dp[i+1][j]=max(dp[i][k]+a[j],dp[i+1][j])
print(max(dp[-1]))