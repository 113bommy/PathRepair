f=[1]
n,mod=map(int,input().split())
for i in range(1,n+1):
    f.append(f[-1]*i%mod)
SUM=0
for i in range(1,n+1):
    SUM+=f[i]*f[n-i+1]*(n-i+1)
    SUM%=mod
print(SUM)