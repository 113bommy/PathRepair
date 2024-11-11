n,t=map(int,input().split())
t=2*t-1
dp=[[[[0,0] for h in range(5)] for j in range(t+2)] for i in range(n+1)]
for h in range(1,5):
    dp[2][0][h][0]=4-h
    dp[2][0][h][1] = h-1

for i in range(2,n):
    for j in range(t+1):
        for h in range(1,5):
            for ne in range(1,5):
                for k in range(2):
                    if (h!=ne):
                        if (k%2):
                            if (ne<h):
                                if (j%2==0):

                                    dp[i+1][j+1][ne][1-k]+=dp[i][j][h][k]
                            else:
                                dp[i+1][j][ne][k]+=dp[i][j][h][k]
                        else:
                            if (ne>h):
                                if (j%2==1):
                                    dp[i+1][j+1][ne][1-k]+=dp[i][j][h][k]
                            else:
                                dp[i+1][j][ne][k]+=dp[i][j][h][k]





ans=0
for h in range(1,4):
    ans+=dp[n][t][h][0]
print(ans)





