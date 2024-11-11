import sys
import math as mt
input=sys.stdin.buffer.readline  
#t=int(input())
mod=10**9+7
n=10**5+1
dp=[0]*(n)
t,k=map(int,input().split())
for i in range(n):
    if i>=k:
        dp[i]=(dp[i-k]%mod+dp[i-1]%mod)%mod
    else:
        dp[i]=1
for i in range(1,n):
    dp[i]=(dp[i-1]%mod+dp[i]%mod)%mod
for __ in range(t):
    a,b=map(int,input().split())
    print((dp[b]-dp[a-1])%mod)
    
    