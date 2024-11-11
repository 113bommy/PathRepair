def check(num):
	first=l[0:num]
	second=l[n-num:n]
	for i in range(num):
		if second[i]-first[i]<m:
			return False
	return True

n,m=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
low=0
high=n//2
while (low<high):
	mid=(low+high)//2
	if check(mid):
		low=mid+1
	else:
		high=mid-1
if check(low):
	print (low)
else:
	print (low-1)