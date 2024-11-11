n,c=map(int,input().split())
l=list(map(int,input().split()))
count=1
for i in range(1,n):
	if(l[i]-l[i-1]>c):
		count=1
	else:
		count+=1
print(count)