def combi(y,x,p=998244353):
  s=fac[y]
  t=fac[x]
  u=fac[y-x]
  ans= (s* pow(t,p-2,p)*pow(u,p-2,p))%p
  return ans

###############################

N,M,K=map(int,input().split())
p=998244353
fac=[1,1]
for i in range(2,N+1):
  fac.append( (fac[-1]*i)%p )


ans=0
for i in range(0,K+1):
  R = ( (M%p) *pow(M-1,N-1-i,p) )%p
  L = combi(N-1,i)
  ans = (ans + (R*L)%p)%p
  
print(ans)