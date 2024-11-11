n,k=map(int,input().strip().split())
l=list(map(int,input().split()))
k1=min(l)
count=0
for x in l:
	p=x-k1
	if p%k!=0:
		print('-1')
		break
	if p%k==0:count+=p//k
else:print(count)