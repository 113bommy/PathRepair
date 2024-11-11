mod = 10**9+7

# N = 15
N = int(input())
xx = list(map(int, input().split()))

a = 1
for i in range(2,N):
    a *= i
    a %= mod

aa = [a]
for i in range(N-2):
    aa.append((aa[-1]+a*pow(i+2,mod-2,mod))%mod)


dx = [xx[i]-xx[i-1] for i in range(1,N)]

ans = 0
for a,d in zip(aa,dx):
    ans += a*d
    ans %= mod

print(ans%mod)
