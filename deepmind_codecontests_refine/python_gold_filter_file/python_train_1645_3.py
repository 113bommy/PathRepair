n=int(input())
mod=998244353

ans=pow(3,n,mod)
rmv=0
f = [1, 1]  
inv = [1, 1]  
finv=[1,1]
for i in range(2, n+1):
    f.append((f[-1] * i) % mod)
    inv.append((-inv[mod % i] * (mod // i)) % mod)
    finv.append(finv[-1]*inv[-1]%mod)

k=n//2
if k*2<=n:
    k+=1
tmp=pow(2,n-k+1,mod)
inv2=pow(2,mod-2,mod)
for i in range(k,n+1):
    ans -= f[n]*finv[n-i]*finv[i]*tmp
    tmp*=inv2
    tmp%=mod
print(ans%mod)
    

