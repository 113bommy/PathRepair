from math import inf

n=int(input())
s=input().strip()
a=[int(X) for X in input().split()]
dp=[0]*(n+1)
dp[1]=1
dp[0]=1
dp12=[inf]*(n+1)
dp12[1]=1
dp12[0]=0
c=1
mod=10**9 + 7
for i in range(2,n+1):
    m=10000
    for j in range(i,0,-1):
        m=min(a[ord(s[j-1])-97],m)

        if (i-j+1>m):
            break
        #print(m,i)
        dp[i]=(dp[i]+dp[j-1])%mod
        dp12[i]=min(dp12[i],dp12[j-1]+1)
        c=max(c,i-j+1)

print(dp[n])
print(c)
print(dp12[n])