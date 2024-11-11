t=int(input())
a=list(map(int,input().split()))
b=max(a)
c=sum(a)
k=b
count=0
i=0
while count<=c:
	for i in range(t):
		count=count+k-a[i]
	if count>c:
		print(k)
		break
	else:
		k=k+1
		count=0

	