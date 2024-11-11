n,a,b = map(int,input().split())
lim = 10**9+7
def combination(n, r, mod=10**9+7):
    r = min(r, n-r)
    res = 1
    for i in range(r):
        res = res * (n - i) * pow(i+1, mod-2, mod) % mod
    return res

print((pow(2,n,lim)-combination(n,a)-combination(n,b)-1) % lim)
