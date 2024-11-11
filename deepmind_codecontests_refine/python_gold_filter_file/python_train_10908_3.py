n,k=map(int,input().split())
MOD=10**9+7
ans=0

baig=[0]*(10**5+1)
exg=[0]*(10**5+1)

for i in range(1,k+1):
    baig[i]=pow(k//i,n,MOD)

for j in range(k,0,-1):
    exg[j]=baig[j]
    for jj in range(2*j,k+1,j):
        exg[j]-=exg[jj]
    exg[j]%=MOD
    ans+=exg[j]*j
    ans%=MOD

print(int(ans))

