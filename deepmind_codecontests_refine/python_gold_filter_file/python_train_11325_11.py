def cmb(n,k,p):
    x,y = 1,1
    for i in range(k):
        x = x * (n-i) % p
        y = y * (i+1) % p
    res = x * pow(y,p-2,p) % p
    return res

N,A,B = map(int,input().split())
mod = 10**9+7
print((pow(2,N,mod)-cmb(N,A,mod)-cmb(N,B,mod)-1)%mod)