n,x,y=map(int,input().split())
a=list(map(int, input().split()))
cy=0
j=0
i=1
while i<n and cy!=y:
	if a[i]>=a[j]:
		cy=cy+1
	else:
		j=i
		cy=0
	i=i+1
print(j+1)