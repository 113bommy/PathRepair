from itertools import permutations
N,M,R=map(int,input().split())
r = [int(i) for i in input().split()]
inf=10**10
#[k][j][i]
dp=[[[inf]*N for i in range(N)]for i in range(N+1)]
for i in range(M):
    a,b,c=map(int,input().split())
    dp[0][a-1][b-1]=c
    dp[0][b-1][a-1]=c
for k in range(1,N+1):
    for j in range(N):
        for i in range(N):
            dp[k][j][i]=min(dp[k-1][j][i],dp[k-1][j][k-1]+dp[k-1][k-1][i])

ans =inf
for elem in permutations(r, R):
    dis=0
    for i in range(R-1):
        dis+=dp[N][elem[i+1]-1][elem[i]-1]
    ans=min(ans,dis)
print(ans)