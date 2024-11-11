n,s=map(int,input().split())
c=s
for i in range(n):
	f,t=map(int,input().split())
	c=max(c,f+t)
print(c)