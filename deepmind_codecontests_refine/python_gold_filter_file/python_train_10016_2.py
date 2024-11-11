t=int(input())
for _ in range(t):
	n,m=map(int,input().split())
	a=list(map(int,input().split()))[::-1]
	b=list(map(int,input().split()))
	min_idx=n
	d={}
	for i in range(n):
		d[a[i]]=i
	ans=0
	on_top=0
	for i in b:
		if d[i]>min_idx:
			on_top-=1
			ans+=1
		else:
			on_top+=min_idx-d[i]-1
			ans+=2*on_top+1
			min_idx=d[i]
		#print(on_top,min_idx)
	print(ans)
