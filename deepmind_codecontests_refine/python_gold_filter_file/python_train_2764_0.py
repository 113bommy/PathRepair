import sys
sys.setrecursionlimit(1000000)

def f(dp,x,y,n):
    if dp[n]!=-1:
        return dp[n]   
    if n%2==1:
        ans=x+min(f(dp,x,y,n-1) ,f(dp,x,y,n+1))
    else:
        ans=f(dp,x,y,n//2)+min(y,x*n//2)
    dp[n]=ans
    return ans

n,x,y=map(int,input().split())
dp=[-1 for i in range(n+10)]
dp[1]=x
print(f(dp,x,y,n))
