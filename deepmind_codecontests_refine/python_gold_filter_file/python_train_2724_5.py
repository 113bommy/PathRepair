n1,n2,k1,k2=map(int,input().split())
dp=[[[0 for i in range(n1+1)] for i in range(n2+1)] for i in range(2)]

pri=10**8
dp[0][1][0]=1
dp[1][0][1]=1
#i denotes n2 soldiers
#j denotes n1 soldiers
for i in range(n2+1):
    for j in range(n1+1):
    
        if(i==0 and j==0):
            continue;
        if(i==1 and j==0):
            continue;
        if(i==0 and j==1):
            continue;
        dp[0][i][j]=dp[0][i-1][j]+dp[1][i-1][j]
        dp[1][i][j]=dp[0][i][j-1]+dp[1][i][j-1]
        print
        if(i>k2):
            if(j==0):
                dp[0][i][j]=0
            dp[0][i][j]-=dp[1][i-k2-1][j]
        if(j>k1):
            if(i==0):
                dp[1][i][j]=0
            dp[1][i][j]-=dp[0][i][j-k1-1]
        dp[0][i][j]=dp[0][i][j]%pri
        dp[1][i][j]=dp[1][i][j]%pri
print((dp[0][-1][-1]+dp[1][-1][-1])%pri)



