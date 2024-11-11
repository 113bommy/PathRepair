n,m=map(int,input().split())
a=min(n,m);z=1
for x in range(1,a+1):
	z=z*x;
print(z)