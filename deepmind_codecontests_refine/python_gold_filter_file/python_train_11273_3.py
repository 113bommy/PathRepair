def mod_fact(n, m) :
    ans =1 
    for i in range(1, n+1) : 
        ans = ((ans%m) * (i%m))%m
    return ans

def mod_div(a,b,md):
    a%=md
    b%=md

    return (a * (pow(b,md-2,md)))%md

MOD = 998244353
n = int(input())
arr = list(map(int,input().split()))
arr.sort()
su = abs(sum(arr[:n]) - sum(arr[n:]))%MOD
combs = mod_div(mod_fact(2*n,MOD), pow(mod_fact(n,MOD),2,MOD), MOD)
print((su*combs)%MOD)
