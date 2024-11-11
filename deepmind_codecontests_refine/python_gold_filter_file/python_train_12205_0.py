from sys import stdin
s=stdin.readline().strip()
k=int(stdin.readline().strip())
n=len(s)
dp=[[[[ None for tt in range(2)]for i in range(2)] for j in range(k+1)] for k1 in range(n)]
dp1=[[[[ None for tt in range(2)]for i in range(2)] for j in range(k+1)] for k1 in range(n)]

def sol(i,j,t,c):
    if i==n:
        if j!=0:
            return -10000000
        else:
            return 0

    if dp[i][j][t][c]!=None:
        return dp[i][j][t][c]
    ans=0
    if c==-1:
        c=(s[i]=="F")
    if c:
        if t:
            ans=-1+sol(i+1,j,t,-1)
        else:
            ans=1+sol(i+1,j,t,-1)
        if j>0:
            ans=max(ans,sol(i,j-1, t,0))
    else :
        ans=sol(i+1,j,not t,-1)
        if j>0:
            ans=max(ans,sol(i,j-1, t,1))
    dp[i][j][t][c]=ans
    return dp[i][j][t][c]
def sol1(i,j,t,c):
    if i==n:
        if j!=0:
            return 10000000
        else:
            return 0
    if dp1[i][j][t][c]!=None:
        return dp1[i][j][t][c]
    ans=0
    if c==-1:
        c=(s[i]=="F")
    if c:
        if t:
            ans=-1+sol1(i+1,j,t,-1)
        else:
            ans=1+sol1(i+1,j,t,-1)
        if j>0:
            ans=min(ans,sol1(i,j-1, t,0))
    else :
        ans=sol1(i+1,j,not t,-1)
        if j>0:
            ans=min(ans,sol1(i,j-1, t,1))
    dp1[i][j][t][c]=ans
    return dp1[i][j][t][c]
print(max(sol(0,k,0,-1),-sol1(0,k,0,-1)))
                
                
