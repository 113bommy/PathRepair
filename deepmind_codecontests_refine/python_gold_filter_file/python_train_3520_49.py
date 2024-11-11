#N

N=int(input())
a=list(map(int,input().split()))

S=[0]*(N+1)
for i in range(N):
    S[i+1]=S[i]+a[i]


#dp[i][j]は[i,j)の範囲で全てをマージする最小コスト
inf=10**15
dp=[[inf]*(N+1) for _ in range(N+1)]

#区間[i,j)を[i,k)+[k,j)に分けて考える
for d in range(1,N+1):#dはj-i
    for i in range(N+1):
        j=i+d
        if j>N:
            break
        if d==1:
            dp[i][j]=0
        else:
            for k in range(i,j):
                dp[i][j]=min(dp[i][j] , dp[i][k]+dp[k][j]+S[j]-S[i])
            
print(dp[0][-1])
            

