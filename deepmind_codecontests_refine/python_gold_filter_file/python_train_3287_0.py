def f(n,m,k,x):
	k1 = k-1
	k2 = n-k
	
	if k1>x-1:
		ll = ((x-1)*x//2) + (k1-x+1)
	else:
		ll = (x*k1) - (k1*(k1+1)//2)

	if k2>x-1:
		rr = ((x-1)*x//2) + (k2-x+1)
	else:
		rr = (x*k2) - (k2*(k2+1)//2)
	return rr+ll+x<=m

iarr = list(map(int,input().split()))
n = iarr[0]
m = iarr[1]
k = iarr[2]
l = 1
r = m
while l<=r:
	mid = (l+r)//2
	if f(n,m,k,mid):
		#print("y",mid)
		l = mid+1
	else:
		r = mid-1
		#print("n",mid)
	#print(l)
print(l-1)
