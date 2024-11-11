N,M = map(int,input().split(" "))
fact = {}
for i in range(2,M):
    while (M%i == 0):
        if i in fact:
            fact[i] += 1
        else:
            fact[i] = 1
        M //= i
    if (M == 1):
        break


MOD = 10**9+7

def nCr_mod(n,r,mod): #nCrmod
    r = min(n-r,r)
    v = 1
    for i in range(r):
        v = (v * ((n-i)%mod) * pow((i+1),mod-2,mod)) % mod
    return v

ans = 1
for key,item in fact.items():
    ans *= nCr_mod((item + (N) - 1),N-1,MOD)
    ans %= MOD
print(ans)