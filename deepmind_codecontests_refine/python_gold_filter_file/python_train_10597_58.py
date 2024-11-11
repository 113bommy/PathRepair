import sys
input=sys.stdin.readline

n,m=map(int,input().split())
inf=10**9+7
dp=[inf]*(2**n)
dp[0]=0

for i in range(m):
    a,b=map(int,input().split())
    C=list(map(int,input().split()))
    bit=0
    for i in C:
        bit|=(1<<(i-1))
    for j in range(2**n):
        dp[j|bit]=min(dp[j|bit],dp[j]+a)

if dp[-1]>=inf:
    print(-1)
else:
    print(dp[-1])