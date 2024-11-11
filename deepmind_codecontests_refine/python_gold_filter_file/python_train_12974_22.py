n,t=map(int,input().split())
l=list(map(int,input().split()))
c,i=0,0
while t>c:
	c+=86400-l[i]
	i+=1
print(i)