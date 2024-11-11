from functools import reduce
mod=10**9+7

def f(A):
 dem=reduce(lambda x,y:x*y%mod,range(n,n-A,-1))
 num=reduce(lambda x,y:x*y%mod,range(1,A+1))
 return dem*pow(num,mod-2,mod)%mod

stdin=open(0)
n,a,b=map(int,stdin.read().split())
ans=pow(2,n,mod)-f(a)-f(b)-1
ans%=mod
print(ans)