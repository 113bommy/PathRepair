N,M=map(int,input().split())
dp=[float("inf") for _ in range(2**N)]
dp[0]=0
for _ in range(M):
    a,b=map(int,input().split())
    c=sum([2**(int(i)-1) for i in input().split()])
    for v in range(2**N):
        nv=v|c
        dp[nv]=min(dp[nv],dp[v]+a)
if dp[-1]==float("inf"):
    print(-1)
else:
    print(dp[-1])