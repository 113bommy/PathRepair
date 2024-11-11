s=input()
t=input()
m,n=len(s),len(t)
dp=[[0]*(n+1)for _ in range(m+1)]
for i in range(m):
    for j in range(n):
        if s[i]==t[j]:
            dp[i+1][j+1]=dp[i][j]+1
        else:
            if dp[i+1][j]>dp[i][j+1]:
                dp[i+1][j+1]=dp[i+1][j]
            else:
                dp[i+1][j+1]=dp[i][j+1]
a,b=m,n
tmp=''
while a and b:
    if s[a-1]==t[b-1]:
        a-=1
        b-=1
        tmp+=s[a]
    elif dp[a][b]==dp[a-1][b]:
        a-=1
    else:
        b-=1
print(tmp[::-1])
