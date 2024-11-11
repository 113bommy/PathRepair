t_p=int(input())
for _ in range(t_p):
    n=int(input())
    t=list(map(int,input().split()))
    t.sort()
    dp=[[100000 for j in range(2*n+2)] for i in range(n+1)]
    for i in range(2*n+2):
        dp[0][i]=0
    for i in range(1,n+1):
        for j in range(i,2*n+2):
            dp[i][j]=min(dp[i][j] , dp[i][j-1] , dp[i-1][j-1]+abs(j-t[i-1]))
    print(dp[-1][-1])
        
