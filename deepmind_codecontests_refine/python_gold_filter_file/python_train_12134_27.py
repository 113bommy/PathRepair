n=int(input())
a=list(map(int,input().split()))
c=1
r=[]
for i in range(n-1):
	if(a[i+1]>a[i]):
		c=c+1
	else:
		r.append(c)
		c=1
r.append(c)
print(max(r))