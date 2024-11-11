
import sys
from sys import stdin

ans = 0
n,m = map(int,stdin.readline().split())
mod = 998244353

a = [list(map(int,stdin.readline().split())) for i in range(n)]

fac = 1
for i in range(1,n+1):
    fac *= i
inv = pow(fac,mod-2,mod)

for j in range(m):

    na = [a[i][j] for i in range(n)]
    na.sort()

    now = 1
    able = 0

    for i in range(n):
        while len(na) > 0 and na[-1] > n-i:
            del na[-1]
            able += 1

        now *= able
        able -= 1

    ans += now * inv
    ans %= mod

    #print (ans)

print ((m-ans) % mod)

    
