mod=10**9+7
n,m=map(int,input().split())
fibo=[1,2]
for i in range(3,max(m,n)+1):
	fibo.append((fibo[-1]+fibo[-2])%mod)
print ((2*(fibo[n-1]+fibo[m-1]-1))%mod)