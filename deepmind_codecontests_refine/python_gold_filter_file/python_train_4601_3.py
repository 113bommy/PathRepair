import sys
t=int(sys.stdin.readline())
for _ in range(t):
    n=int(sys.stdin.readline())
    a=[0 for x in range(n)]
    b=[0 for x in range(n)]
    dp=[[0,0,0] for x in range(n)]
    u,v=map(int,sys.stdin.readline().split())
    a[0],b[0]=u,v
    dp[0]=[0,v,2*v]
    for i in range(1,n):
        u,v=map(int,sys.stdin.readline().split())
        a[i],b[i]=u,v
        if a[i]==a[i-1]:
            dp[i][0]=min(dp[i-1][1],dp[i-1][2])
            dp[i][1]=v+min(dp[i-1][0],dp[i-1][2])
            dp[i][2]=2*v+min(dp[i-1][0],dp[i-1][1])
        elif abs(a[i]-a[i-1])>2:
            dp[i]=[min(dp[i-1]),min(dp[i-1])+v,min(dp[i-1])+2*v]
        elif a[i]-a[i-1]==2:
            dp[i][0]=min(dp[i-1][0],dp[i-1][1])
            dp[i][1]=min(dp[i-1])+v
            dp[i][2]=min(dp[i-1])+2*v
        elif a[i]-a[i-1]==1:
            dp[i][0]=min(dp[i-1][0],dp[i-1][2])
            dp[i][1]=min(dp[i-1][0],dp[i-1][1])+v
            dp[i][2]=min(dp[i-1])+2*v
        elif a[i]-a[i-1]==-1:
            dp[i][0]=min(dp[i-1])
            dp[i][1]=min(dp[i-1][1],dp[i-1][2])+v
            dp[i][2]=min(dp[i-1][0],dp[i-1][2])+2*v
        else:
            dp[i][0]=min(dp[i-1])
            dp[i][1]=min(dp[i-1])+v
            dp[i][2]=min(dp[i-1][1],dp[i-1][2])+2*v
    #print(dp)
    print(min(dp[n-1]))
        
