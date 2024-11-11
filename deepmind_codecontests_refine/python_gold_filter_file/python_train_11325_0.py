def comb2(n, r):
    if r<0 or r>n:
        return 0
    r=min(r, n-r)
    res=1
    for i in range(r):
        res=res*(n-i)%MOD*pow(i+1, MOD-2, MOD)%MOD
    return res

MOD=10**9+7

N, A, B=map(int, input().split())
ans=pow(2, N, MOD)-comb2(N, A)-comb2(N, B)-1
print(ans%MOD)