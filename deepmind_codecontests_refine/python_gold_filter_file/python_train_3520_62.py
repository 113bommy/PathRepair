# 大きさがsum(a)のスライムが1匹いる
# dp[l][r]=min(区間[l,r]を分解するための最小コスト)
import sys
sys.setrecursionlimit(1000000000)
input = sys.stdin.readline
INF=10**15
n=int(input())
a=list(map(int,input().split()))
b=[0]*(n+1)
for i in range(n):
    b[i+1]=b[i]+a[i]
dp=[[-1]*n for i in range(n)]
for i in range(n):
    dp[i][i]=0
def memo(i,j):
    if dp[i][j]>=0:
        return dp[i][j]
    ans=INF
    for k in range(i,j):
        ans=min(ans,memo(i,k)+memo(k+1,j))
    dp[i][j]=ans+b[j+1]-b[i]
    return dp[i][j]
print(memo(0,n-1))