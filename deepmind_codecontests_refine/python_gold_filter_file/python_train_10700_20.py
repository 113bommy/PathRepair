n,k,*p=map(int,open(0).read().split())
s=m=k
for i in range(n):s+=p[i]-p[i-k]*(i>=k);m=max(m,s)
print(m/2)