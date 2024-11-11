def ncr(n, r, p): 
    # initialize numerator 
    # and denominator 
    num = den = 1 
    for i in range(r): 
        num = (num * (n - i)) % p 
        den = (den * (i + 1)) % p 
    return (num * pow(den,p - 2, p)) % p 
mod=998244353 
n,m=map(int,input().split())
if n>2:
    ans=ncr(m,n-1,mod)
    ans=ans*(n-2)
    ans=ans%mod
    ans=ans*pow(2,n-3,mod)
    ans=ans%mod
    print(ans)
else:
    ans=m%mod
    print(0)