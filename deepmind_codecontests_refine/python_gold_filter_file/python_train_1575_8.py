from math import factorial as f
mod = 998244353

n,m,k = map(int,input().split())

ans=1
for i in range(k):
    ans=(ans*(m-1))%mod

ans=(ans*m)%mod

val = f(n-1)//(f(k)*f(n-1-k))

ans=(ans*val)%mod

print(ans)