n,m,k=map(int,input().split())
mod=998244353
if m==1:print(0 if k!=n-1 else 1);exit()
fact=[1]*(n-1+1)
inv=[1]*(n-1+1)
for i in range(2,n-1+1):
    fact[i]=i*fact[i-1]%mod
inv[-1]=pow(fact[-1],mod-2,mod)
for i in range(n-1,1,-1):
    inv[i-1]=inv[i]*i%mod
def comb(x,y):return fact[x]*inv[y]%mod*inv[x-y]%mod
ans=0
po=pow(m-1,n-1,mod)*m%mod
ue=fact[n-1]
iii=pow(m-1,mod-2,mod)%mod
for i in range(k+1):
    ans+=comb(n-1,i)*po%mod
    po*=iii
    po%=mod
print(ans%mod)