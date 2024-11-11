def lcs(s1,s2):
   dp=[[0 for _ in range(m+1)]for _ in range(n+1)]
   ans=0
   for i in range(1,n+1):
    for j in range(1,m+1):
        if s1[i-1]==s2[j-1]:
            dp[i][j]=2+dp[i-1][j-1]
        else:
          dp[i][j]=max(-1+dp[i-1][j],dp[i][j-1]-1,0)
        ans=max(ans,dp[i][j])
   return ans

n,m=map(int,input().split())
s1=input()
s2=input()
print(lcs(s1, s2))
