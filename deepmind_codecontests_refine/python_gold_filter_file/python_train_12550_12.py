a=input().split()
n=int(a[0])
c=int(a[1])
b=input().split()
seconds=[int(i) for i in b]
count=1
k=1
while k<n:
	if seconds[k]-seconds[k-1]<=c:
		count+=1
	else:
		count=1
	k+=1
print(count)
