import sys
import itertools
input = sys.stdin.readline

n=int(input())
a= list(map(int, input().split()))
a+=a
b=itertools.accumulate(a)
b=[0]+list(b)
INF=10**15
dp=[[INF] *(2*n+1) for i in range(2*n+1)]
# dp[i][j][0]: コスト
# dp[i][j][1]:合成したスライムの合計

for i in range(n):
    for l in range(2*n-i):
        r=l+i
        if r==l:
            dp[l][r]=0
        else:
            # 合成の仕方を確定
            for k in range(l,r):
                dp[l][r]=min(dp[l][k]+dp[k+1][r]+b[r+1]-b[l],dp[l][r])

print(dp[0][n-1])