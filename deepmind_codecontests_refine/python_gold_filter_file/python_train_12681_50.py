s=input()
t=input()
n1,n2=len(s),len(t)
dp=[[0]*(n1+1) for i in range(n2+1)]
st=''
for i in range(1,n2+1):
    for j in range(1,n1+1):
        if s[j-1]==t[i-1]:
            dp[i][j]=dp[i-1][j-1]+1
            #st+=s[j-1]
        else:
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])
while i>0 and j>0:
    if t[i-1]==s[j-1]:
        st=s[j-1]+st
        i-=1
        j-=1
    elif dp[i][j-1]>dp[i-1][j]:
        j-=1
    else:
        i-=1
print(st)