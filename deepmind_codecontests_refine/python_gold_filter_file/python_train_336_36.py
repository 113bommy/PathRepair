from sys import stdin
import math
inp = lambda : stdin.readline().strip() 

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        return None
    else:
        return x % m


def factorialMod(n, modulus):
    ans=1
    if n <= modulus//2:
        for i in range(1,n+1):
            ans = (ans * i) % modulus
    else:
        for i in range(1,modulus-n):
            ans = (ans * i) % modulus
        ans = modinv(ans, modulus)

        if n % 2 == 0:
            ans = -1*ans + modulus
    return ans % modulus

n = int(inp())
print((factorialMod(n,10**9+7)- pow(2,n-1,10**9+7))%(10**9+7))