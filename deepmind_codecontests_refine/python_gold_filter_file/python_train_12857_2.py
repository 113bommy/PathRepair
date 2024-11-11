import sys
n, k = map(int, input().split())
def getNumber(l, r, num):
    d = l // num
    if d *num  < l:
        d += 1
    l = num *d
    if( l > r):
        return 0
    return (r - l) // num  + 1
ans = 1
mod = 10 ** 9 + 7
a = list(map(int, input().split()))
b = list(map(int, input().split()))

for i in range(0, n//k):
    if b[i] == 0:
        ans *= (getNumber(10 **(k -1),10 ** (k)  - 1,a[i])) %mod
    elif b[i] == 9:
        ans *= (getNumber(0,10**(k) - 1 - 10**(k -1),a[i])) % mod
    else:
        ans *= (getNumber(0, (10**(k - 1)) * b[i] -1,a[i]) % mod + getNumber((10**(k - 1)) * (b[i]+1),10**(k) - 1,a[i]) % mod)%mod
    ans %= mod
print(ans)
    
    