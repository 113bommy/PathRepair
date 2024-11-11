s1=input()
s2=input()
n=len(s1)
m=len(s2)
# import numpy as np
dp=[[0 for i in range(m+1)]for i in range(n+1)]
for i in range(1,n+1):
    for j in range(1,m+1):
        if s1[i-1]==s2[j-1]:
            dp[i][j]=dp[i-1][j-1]+1
        else:
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])
# print(np.array(dp))
ans=""
# print(dp[-1][-1])
i=n
j=m
while i>0 and j>0:
    if dp[i][j]==dp[i-1][j]:
        i-=1
    elif dp[i][j]==dp[i][j-1]:
        j-=1
    else:
        ans=s1[i-1]+ans
        i-=1
        j-=1
print(ans)