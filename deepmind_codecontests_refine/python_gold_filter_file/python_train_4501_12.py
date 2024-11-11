n,m=map(int,input().split())
md=998244353

def ncr(n, r, p): 
    num = den = 1 
    for i in range(r): 
        num = (num * (n - i)) % p 
        den = (den * (i + 1)) % p 
    return (num * pow(den,  
            p - 2, p)) % p 
if(n==2):
    print("0")
else:
    ans1=1
    for i in range(n-3):
        ans1*=2
        ans1%=md
    ans1=(ans1%md * (n-2)%md)%md
    t=ncr(m,n-1,md)
    ans1=(ans1%md *t%md)%md
    print(ans1)
    
