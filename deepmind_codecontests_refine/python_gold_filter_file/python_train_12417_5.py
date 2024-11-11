import math


# Function to find modulo inverse of b. It returns
# -1 when inverse doesn't
# modInverse works for prime m
mod = 10**9 + 7
def modInverse(b):
    return pow(b, mod - 2, mod)
def modDivide(a, b):
    a = a % mod
    inv = modInverse(b)
    return (inv * a) % mod
def solve():
    arr = list(map(int,list(input())))
    if (len(arr) == 1):
        print(0)
        return 0
    t = 0
    l = len(arr)
    R = 0
    for i in range(l-2,-1,-1):
        R += (pow(10,(l-i-1-1),mod)*(l-i-1))%mod

        R%=mod
        t+=(arr[i]*R)%mod
        t%=mod
    for i in range(1,l):
        t+= (( ( arr[i] * ( ( i*(i+1)) //2) ) %mod) *pow(10, l-i-1, mod))%mod
        t%=mod
    print(int(t)%mod)
solve()
