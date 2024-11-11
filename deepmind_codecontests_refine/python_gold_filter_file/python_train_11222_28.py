n=int(input());a=list(map(int,input().split()));b=[0];c=0
for i in range(n-1):
	if a[i]>=a[i+1]:
		c+=1;b.append(c)
	else:
		c=0
print(max(b))