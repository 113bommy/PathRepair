# dp[n][i][j]=(頂点iから頂点jへ行く長さnのパスの個数)
# dp[n][i][j]=sum(dp[n-1][i][k]*a[k][j])⇒DP[n]=DP[n-1]*A DP[0]=Eより DP[n]=A^n
n,k=map(int,input().split())
a=[list(map(int,input().split())) for i in range(n)]
dp=[[0]*n for i in range(n)]
mod=10**9+7
for i in range(n):
    for j in range(n):
        dp[i][i]=1
def dot(A,B):
    C=[[0]*n for i in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j]+=A[i][k]*B[k][j]
            C[i][j]%=mod
    return C
while k:
    if k&1:
        dp=dot(dp,a)
    a=dot(a,a)
    k>>=1
ans=0
for i in dp:
    ans+=sum(i)
print(ans%mod)
