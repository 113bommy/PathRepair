x,y=map(int,input().split())
x=min(x,y)
ans=1
for i in range(1,x+1):
	ans*=i
print (ans)
