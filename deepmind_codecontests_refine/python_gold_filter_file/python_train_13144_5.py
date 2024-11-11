t=int(input())
for tt in range(t):
	n=int(input())
	s=input().strip()
	d={}
	d[0]=1
	pre=[0]*(n)
	ans=0
	for i in range(n):
		# print(d)
		pre[i]=int(s[i])
		if i>0:
			pre[i]+=pre[i-1]
		xx=pre[i]-(i+1)
		if xx in d:
			ans+=d[xx]
		if xx in d:
			d[pre[i]-(i+1)]+=1
		else:
			d[xx]=1
	print(ans)