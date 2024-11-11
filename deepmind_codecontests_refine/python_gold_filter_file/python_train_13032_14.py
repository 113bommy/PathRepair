MOD=1000000007

def modexp(v,k):
    res=1
    while k:
        if k&1:
            res=(res*v)%MOD
        k>>=1
        v=(v*v)%MOD
    return res

x,n=map(int,input().split())
div=dict()
from math import sqrt

sq=sqrt(x)
i=2
while(i<=sq):
    if(x%i==0):
        if i not in div:
            div[i]=1
        else:
            div[i]+=1
        x//=i
        sq=sqrt(x)
    else:
        i+=1
if x not in div:
    div[x]=1
else:
    div[x]+=1

ans=1
for p in div:
    cnt=div[p]
    val=p
    c=0
    while(val<=n):
        c=(c+(n//val))
        val*=p
    ans=(ans*modexp(p,c))%MOD

print(ans)