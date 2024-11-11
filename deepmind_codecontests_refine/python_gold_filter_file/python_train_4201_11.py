s="A"+input()+"a"
ind=0
ind1=0
for i in range(len(s)):
    if s[i]<"a":
        ind+=1
for i in range(len(s)-1,-1,-1):
    if s[i]>"Z":
        ind1+=1
s1="A"*ind+"a"*ind1
ans=0
for i in range(len(s)):
    if s[i]<"a" and s1[i]>="a":
        ans+=1
    elif s[i]>="a" and s1[i]<"a":
        ans+=1    
dp=[[0 for i in range(2)]for j in range(len(s)+2)]
for i in range(1,len(s)):
    if s[i-1]<"a" and s[i]>="a":
        dp[i][0]=min(dp[i-1][0],dp[i-1][1])
        dp[i][1]=dp[i-1][0]+1
    elif (s[i-1]>="a" and s[i]<"a"):
        dp[i][0]=dp[i-1][1]
        dp[i][1]=dp[i-1][0]+1
    else:
        dp[i][0]=dp[i-1][0]
        dp[i][1]=dp[i-1][1]+1

print(min(dp[len(s)-1]))  


