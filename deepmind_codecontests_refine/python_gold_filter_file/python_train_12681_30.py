s=str(0)+input()
t=str(0)+input()

dp=[[0]*(len(t)) for i in range(len(s))]

for i in range(1,len(s)):
    for j in range(1,len(t)):
        if s[i]==t[j]:
            dp[i][j]=dp[i-1][j-1]+1
        else:dp[i][j]=max(dp[i-1][j],dp[i][j-1])

ans=[""]*dp[i][j]
i=len(s)-1
j=len(t)-1
k=dp[i][j]-1
while i>0 and j>0:
    if s[i]==t[j]:
        ans[k]=s[i]
        k-=1
        i-=1
        j-=1
    elif dp[i][j]==dp[i-1][j]:i-=1
    elif dp[i][j]==dp[i][j-1]:j-=1

print("".join(ans))