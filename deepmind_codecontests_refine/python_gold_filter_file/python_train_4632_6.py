n,k,p,maxsum,minmed=[int(x) for x in input().split()]
left=n-k
stillnow=0
lessthanmed=0
ks=[int(x) for x in input().split()]
for i in ks:
	stillnow+=i
	if i<minmed:
		lessthanmed+=1
if lessthanmed>n//2:
	print(-1)
	exit()
minpermit=min(n//2-lessthanmed,n-k)
toprint=[1]*minpermit+[minmed]*(n-k-minpermit)
if sum(toprint)+stillnow>maxsum:
	print(-1)
	exit()
print(' '.join([str(x) for x in toprint]))
