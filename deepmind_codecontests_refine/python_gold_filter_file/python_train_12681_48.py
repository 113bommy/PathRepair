S=input()
T=input()
s=len(S)
t=len(T)
#dp[i][j] Sのi文字目までとTのj文字目までで最大共通文字数
dp=[[0]*(t+1) for i in range(s+1)]
for i in range(s):
    for j in range(t):
        if S[i]==T[j]:
            dp[i+1][j+1]=max(dp[i][j]+1, dp[i][j])
        else:
            dp[i+1][j+1]=max(dp[i+1][j], dp[i][j+1])
ans=''
while s>0 and t>0:
    if dp[s][t]==dp[s-1][t]:
        s-=1
    elif dp[s][t]==dp[s][t-1]:
        t-=1
    else:
        s-=1
        t-=1
        ans+=T[t]
ans=ans[::-1]
print(ans)