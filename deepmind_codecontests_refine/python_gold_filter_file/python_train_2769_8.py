
n,m=map(int,input().split())
a=min(n,m)
b=1
for i in range(1,a+1):
	b*=i
print(b)