import sys
stdin = sys.stdin

def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

# nの逆元のリスト
def inv_mod(n:int, mod:int) -> list:
    inv = [0,1]
    for i in range(2,n+1):
        inv.append(mod - ((mod//i)*inv[mod%i]) % mod)
    return inv
       
# nの階乗のリスト
def fact(n:int, mod:int) -> list:
    fac = [1,1]
    res = 1
    for i in range(2,n+1):
        res = res*i%mod
        fac.append(res)
    return fac

# nの階乗の逆元のリスト
def fact_inv(n:int, inv:list, mod:int) -> list:
    facInv = [1,1]
    for i in range(2,n+1):
        facInv.append(facInv[i-1]*inv[i] % mod)
    return facInv
        
# 二項係数
def nCr(n:int, r:int, mod:int, fac:list, facInv:list) -> int:
    if not (0<=r and r<=n):
        return 0
    
    return ((fac[n]*facInv[r]) % mod) * facInv[n-r] % mod

MOD = 998244353

k,n = li()

inv = inv_mod(n+k,MOD)
fac = fact(n+k,MOD)
facInv = fact_inv(n+k,inv,MOD)

answers = []
if k == 1:
    print(0)

else:
    for t in range(2,k+2):
        p = t//2
        ans = 0
        if t%2 == 0:
            temp = 0
            for q in range(p):
                temp = temp + nCr(p-1,q,MOD,fac,facInv) \
                              * (2**q) \
                              * nCr(n+k-2*p,n-q,MOD,fac,facInv)
                temp %= MOD
                
                temp = temp + nCr(p-1,q,MOD,fac,facInv) \
                              * (2**q) \
                              * nCr(n+k-2*p-1,n-q-1,MOD,fac,facInv)
                temp %= MOD
                
            ans = temp%MOD
        
        else:
            temp = 0
            for q in range(p+1):
                temp = temp + nCr(p,q,MOD,fac,facInv) \
                              * (2**q) \
                              * nCr(n+k-2*p-1,n-q,MOD,fac,facInv)
                temp %= MOD
            
            ans = temp%MOD
            
        answers.append(ans)
        print(ans)
        
for ans in answers[-2::-1]:
    print(ans)
    