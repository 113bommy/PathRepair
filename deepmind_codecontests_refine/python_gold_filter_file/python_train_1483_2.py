n,m=map(int,input().split())
new=list(map(int,input().split()))
a = []
if sum(new)<n:
	print (-1)
	exit()
for i in range(m):
	if new[i]+i>n:
		print (-1)
		exit()
for i in range(m):
	a.append((new[i],i))
suff=[-1]*m
suff[-1] = a[-1][0]
for i in range(m-2,-1,-1):
	suff[i] = suff[i+1]+a[i][0]
ans = [i for i in range(1,m+1)]
for i in range(m):
	ans[i] = max(ans[i],n-suff[i]+1)
print (*ans)