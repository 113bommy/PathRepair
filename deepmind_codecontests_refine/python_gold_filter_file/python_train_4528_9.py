n=int(input())
a=list(map(int,input().split()))
a.sort()
c=0
for i in range(1,n):
	if a[i]<a[i-1]:
		x=(a[i-1]-a[i])+1
		a[i]=a[i]+x
		c=c+x
	elif a[i]==a[i-1]:
		a[i]=a[i]+1
		c=c+1

print(c)