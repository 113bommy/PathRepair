def Pow(a, n):
    if n == 0: return 1
    if n%2 == 0:
        return (Pow(a, n//2))**2%mod
    else:
        return Pow(a, n-1)*a%mod
mod = 998244353
N, M, K = map(int, input().split())
x = [1]*N
for i in range(1,N):
    x[i] = Pow(i, mod-2)
cmb = [1]*N
for i in range(N-2):
    cmb[i+1] = ((cmb[i]*(N-1-i))%mod*x[i+1])%mod
ans = 0
for i in range(K+1):
    num = Pow(M-1, N-1-i)
    ans = (ans+M*num%mod*cmb[i]%mod)%mod
print(ans)