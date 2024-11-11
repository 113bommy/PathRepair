n,m=map(int,input().split())
x=min(n,m)+1
print(x)
for i in range(x):
	print(i,x-1-i)
