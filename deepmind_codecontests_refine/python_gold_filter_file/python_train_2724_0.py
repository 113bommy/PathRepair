
from collections import defaultdict

def ncr(n, r, p):
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den,
                      p - 2, p)) % p

n1,n2,k1,k2  = map(int,input().split())
dp = defaultdict(int)
dp[(0,0,0)] = 1
dp[(0,0,1)] = 1
mod = 100000000
for i in range(0,n1+1):
    for j in range(0,n2+1):
        for x in range(1,k1+1):
          if i>=x:
               dp[(i,j,0)] += dp[(i-x,j,1)]%mod

        for x in range(1,k2+1):
            if j>=x:
               dp[(i,j,1)] += dp[(i,j-x,0)]%mod

        dp[(i,j,0)]%=mod
        dp[(i,j,1)]%=mod


# print(dp)
print((dp[(n1,n2,0)]+dp[(n1,n2,1)])%mod)


