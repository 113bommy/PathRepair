
n,a,b = map(int,input().split())

mod = 10**9+7

def comb(n,r):
	u = 1
	d = 1
	for i in range(n-r+1,n+1):
		u = u*i%mod

	for i in range(1,r+1):
		d = d*i%mod
	D = pow(d,mod-2,mod)

	return u*D%mod

ans = pow(2,n,mod)-1-comb(n,a)-comb(n,b)

print(ans%mod)