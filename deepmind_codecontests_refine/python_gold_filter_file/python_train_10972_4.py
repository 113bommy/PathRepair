n,m,k=map(int,input().split())
mod=10**9+9
x=n-m
if x>=n//k:
    print(m)
else:
    y=n-k*x
    a=y//k
    b=y%k
    c=pow(2,a,mod)
    if c==0:
        c=mod-1
    else:
        c-=1
    ans=((2*k)%mod)*c
    ans%=mod
    ans+=x*(k-1)+b
    ans%=mod
    print(ans)
    
