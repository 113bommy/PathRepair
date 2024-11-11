n,x = (int(i) for i in input().split())
a = [int(i) for i in input().split()]
b,ans = [0],float("inf")
for i in range(n): b.append(b[-1]+a[i])
def f(k):
	m = 5*(b[n]-b[max(0,n-2*k)])
	for i in range((n-k)//k): m+=(2*i+7)*(b[n-(2+i)*k]-b[max(0,n-(3+i)*k)])
	return m+k*x
for i in range(1,(n+1)//2+1): ans = min(f(i),ans)
print(ans+n*x)