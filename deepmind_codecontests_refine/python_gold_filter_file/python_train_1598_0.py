n,l,k=map(int,input().split())
p=list(map(int,input().split()))
b=list(map(int,input().split()))
for j in range(n):
    b[j]+=1

dp=[[[0 for i in range(201)] for j in range(201)] for v in range(201)]
dp[0][0][0]=1

for i in range(n):
    for j in range(i+1):
        for v in range(201):
            dp[i+1][j][v]+=dp[i][j][v]*(1-(p[i]/100))
            dp[i+1][j+1][min(200,v+b[i])]+=dp[i][j][v]*(p[i]/100)



ans=0
for i in range(l,n+1):
    for v in range(201):
        if (k+v)>=i:
            ans+=dp[n][i][v]


print("{0:.9f}".format(ans))




