from sys import stdin
input=stdin.readline

for _ in range(int(input())):
    n=int(input())
    lis=[]
    for i in range(n):
        lis.append(list(map(int,input().split())))
    dp=[]
    for i in range(n):
        dp.append([0]*3)
    dp[0][0]=0
    dp[0][1]=lis[0][1]
    dp[0][2]=lis[0][1]*2
    for i in range(1,n):
        for j in range(3):
            dp[i][j]=lis[i][1]*j
            m=10**18
            for k in range(3):
                if k+lis[i-1][0]!=j+lis[i][0]:
                    m=min(m,dp[i-1][k])
            dp[i][j]+=m
    print(min(dp[-1]))