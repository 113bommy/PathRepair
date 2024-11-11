n,k=map(int,input().split())
ans=0
ss=input().split()
for i in range(n):
	s=ss[i]
	add=0
	for j in s:
		if j=='4' or j=='7':
			add+=1
	if add<=k:
		ans+=1
print(ans)