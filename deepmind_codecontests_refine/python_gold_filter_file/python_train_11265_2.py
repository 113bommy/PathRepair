n=int(input())
a=[int(x) for x in input().split()]
i=1
d=[]
maxi=0
while i<n:
	c=1
	j=i
	while i<n and a[i]>a[i-1]:
		i+=1
		c+=1
	
	d.append([c,j,i])
	i+=1	
	maxi=max(maxi,d[-1][0])

for i in range(len(d)-1):

	if a[d[i][2]-2]<a[d[i+1][1]-1] or (d[i+1][1]!=n and a[d[i][2]-1]<a[d[i+1][1]]):
		maxi=max(maxi,d[i][0]+d[i+1][0]-1)	
print(maxi)	
	