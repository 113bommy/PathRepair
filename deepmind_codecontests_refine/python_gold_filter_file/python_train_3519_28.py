#37 ABC128D
n,k=map(int,input().split())
v=list(map(int,input().split()))

res=[]
for x in range(min(n,k)+1):
	for a in range(x+1):
		b=x-a
		l=v[:a]
		r=v[n-b:]
		z=[]
		for t in l:
			if t<0:
				z.append(-t)
		for t in r:
			if t<0:
				z.append(-t)
		z.sort()
		z=z[::-1]
		res.append(sum(l)+sum(r)+sum(z[:k-x]))
		#print(l,r,z)
print(max(res))