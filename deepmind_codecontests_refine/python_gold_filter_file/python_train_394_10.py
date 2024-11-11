N,x=map(int,input().split())
count=0
c=list(map(int,input().split()))
c.sort()
for i in range(N):
	x=x-int(c[i])
	if x>=0:
		count+=1
if x>0:
	count=count-1
print(count)