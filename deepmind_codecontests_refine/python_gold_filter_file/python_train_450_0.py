def ncr(n, r, p):
    # initialize numerator
    # and denominator
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den,
                      p - 2, p)) % p


p=10**9+7
n,k=map(int,input().split())
b=list(map(int,input().split()))
if k==0:
    print(*b)

else:
    k-=1
    res=[]
    for r in range(1,n+1):
        res.append(ncr(r+k-1,r-1,p))

    ans=[]
    for i in range(n):
        j=i
        val=0
        while(j>=0):
            val+=res[j]*b[i-j]
            j+=-1

        ans.append(val%p)

    print(*ans)





