x,y,l,r = map(int, input().split())
vals=[]
p=1
while p<r:
	z=1
	t=p
	while t+z<=r:
		if(t+z)>=l:
			vals.append(t+z)
		z=z*y
	p=p*x

if(len(vals)==0):
	print(r-l+1)
	exit(0)

vals.sort()
ans = max(vals[0]-l, r-vals[-1])
ans=max(ans, 0)
for i in range(1, len(vals)):
	ans=max(ans, vals[i]-vals[i-1]-1)
print(ans)