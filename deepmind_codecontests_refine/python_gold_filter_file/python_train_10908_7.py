n,k=map(int,input().split())
dp=[0]*(k+1)
mod=int(1e9+7)
for i in range(k,0,-1):
    sm=0
    for j in range(2*i,k+1,i):
        sm=(sm+dp[j])%mod
    dp[i]=(pow(k//i,n,mod)-sm)%mod

ans=0
for i in range(1,k+1):
    ans+=(dp[i]%mod*i%mod)%mod
print(ans%mod)
