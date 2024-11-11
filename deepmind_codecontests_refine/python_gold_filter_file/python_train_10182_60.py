import sys
import bisect
import math
read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
from operator import itemgetter

def calc(n,p,q,r,s,t,u):
    dp=[-1]*(n+1)
    for i in range(n+1):
        dp[i]=i
    dp[0]=0
    for i in range(1,n+1):
        if i>=p and dp[i-p]>=0:
            if dp[i]<dp[i-p]+s:
                dp[i]=dp[i-p]+s
        if i>=q and dp[i-q]>=0:
            if dp[i]<dp[i-q]+t:
                dp[i]=dp[i-q]+t
        if i>=r and dp[i-r]>=0:
            if dp[i]<dp[i-r]+u:
                dp[i]=dp[i-r]+u
    
    return max(dp)

n=int(input())
p,q,r=map(int,readline().split())
s,t,u=map(int,readline().split())

res=calc(n,p,q,r,s,t,u)
ans=calc(res,s,t,u,p,q,r)
print(ans)