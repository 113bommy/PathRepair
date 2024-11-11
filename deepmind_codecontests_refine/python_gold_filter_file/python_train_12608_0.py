from math import ceil, sqrt
mod=10**9+7

def div(n):
    x=set()
    for i in range(ceil(sqrt(n)),0,-1):
        if n%i==0:
            x.add(n//i)
            if (n//i!=i):
                x.add(i)
    return sorted(list(x),reverse=True)
n=int(input())
a=[int(x) for x in input().split()]
dp=[0]*(n+1)
dp[0]=1

for i in range(n):
    #print(div(a[i]))
    for j in div(a[i]):
        if j<=n:
            dp[j]=(dp[j]+dp[j-1])%mod
an=0

for i in range(1,len(dp)):
    an=(an+dp[i])%mod
print(an)