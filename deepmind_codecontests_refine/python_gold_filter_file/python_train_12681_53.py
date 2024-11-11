s=list(input())
t=list(input())

lens=len(s)
lent=len(t)

dp=[[0]*(lent+1) for _ in range(lens+1)]

for i in range(lens):
    for j in range(lent):
        if s[i]==t[j]:
            dp[i+1][j+1]=dp[i][j]+1
        else:
            dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1])

ans=''
i,j=lens,lent

while i>=0 and j>=0:
    if dp[i-1][j]==dp[i][j]:i-=1
    elif dp[i][j-1]==dp[i][j]:j-=1
    else:
        ans=s[i-1]+ans
        i,j=i-1,j-1
print(ans)