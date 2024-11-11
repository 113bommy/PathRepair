N,a,b=map(int,input().split())
MOD=10**9+7
def comb(n,k):
  tmp=1
  for i in range(n-k+1,n+1):
    tmp*=i
    tmp%=MOD
  for i in range(1,k+1):
    tmp*=pow(i,MOD-2,MOD)
    tmp%=MOD
  return tmp
ans = pow(2,N,MOD) - 1 - comb(N,a) - comb(N,b)
print(ans%MOD)
