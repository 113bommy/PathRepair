n,a,b = map(int,input().split())
mod=7+10**9
ans = pow(2 , n , mod)

def comb(n,c,mod):
  s=1
  t=1
  for i in range(1,c+1):
    s=s*i%mod
  for j in range(n-c+1,n+1):
    t=t*j%mod
  return (t*pow(s,mod-2,mod))%mod

print((ans-1-comb(n,a,mod)-comb(n,b,mod))%mod)