n,m=map(int,input().split())
mod=998244353
if n==3:
	print (((m*(m-1))//2)%(mod))
	exit()
if n==2:
	print(0)
	exit()
fact = [1,1]
for i in range(2,max(n,m)+1):
	fact.append((fact[-1]*i)%mod)
ans = pow(2,n-3,mod)
ans = ((n-2)*ans)%mod
ans = ans*((fact[m]*pow((fact[n-1]*fact[m+1-n])%mod,mod-2,mod))%mod)
print ((ans)%mod)