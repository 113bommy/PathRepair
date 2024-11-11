n,k,l,m=map(int,input().split())
fc={1:1,2:1}
def f(n):
	if n not in fc: k=n//2;fc[n]=(f(k+1)**2+f(k)**2 if n%2 else f(k)*(2*f(k+1)-f(k)))%m
	return fc[n]
s=int(k<2**l)
for i in range(l): s*=pow(2,n,m)-f(n+2) if (k>>i)%2 else f(n+2)
print(s%m)
