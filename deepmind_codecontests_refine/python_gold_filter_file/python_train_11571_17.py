

n,v=map(int,input().split(" "))

c=min(n-1,v)
i=2
tot=1
while(i<=(n-v)):
	c+=i
	i+=1

print(c)



