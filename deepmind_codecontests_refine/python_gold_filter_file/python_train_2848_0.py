n,k=map(int,input().split())
l=list(map(int,input().split()))
v=0
for j in range(k,len(l)):
	if l[j]!=l[j-1]:
		v=1
		break
if v==1:
	print(-1)
else:
	c=0
	for j in range(k-2,-1,-1):
		if l[j]==l[k-1]:
			c+=1
		else:
			break
	print(k-1-c)
