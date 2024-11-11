
#with recursion
def binpow(a,n,m):
    if n==0:
        return(1)
    x = binpow(a,n//2,m)
    x=(x*x)%m
    if (n%2==1):
        x = (x*a)%m
    return(x)

#without recursion
def binpow1(a,n,m):
    r = 1
    while(n>0):
        if (n&1):
            r = (r*a)%m
        a = (a*a)%m
        n=n>>1
    return(r)

n = int(input())

ans = 0
if n>3:
    ans += 36*(n-3)*pow(4,n-4)
ans += 24*pow(4,n-3)
print(ans)
