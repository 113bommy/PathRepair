from sys import stdin,stdout
import math
nmbr = lambda: int(input())
lst = lambda:list(map(int,input().split()))
def ncr(n,r):
    lim=min(r,n-r)
    num,den=n,1
    nn=dd=1
    for i in range(lim):
        nn*=num
        dd*=den
        num-=1
        den+=1
    return nn//dd
for _ in range(1):#nmbr():
    n,k=lst()
    dp=[0]*(1+n)
    dp[1]=0
    dp[2]=1
    for i in range(3,n+1):
        dp[i]=(i-1)*(dp[i-1]+dp[i-2])
    sm=p=0
    while p<=k:
        sm+=ncr(n,p)*dp[p]
        p+=1
    print(sm+1)