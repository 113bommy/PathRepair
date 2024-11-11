N,K,*L=map(int,open(0).read().split())
S=sorted([(d,t)for t,d in zip(*[iter(L)]*2)],reverse=True)
In=set()
C=X=0
uni=[]
dub=[]
for d,t in S:
	if t not in In:
		In.add(t)
		uni.append(d)
		X+=1
		if X==K:
			break
	else:
		dub.append(d)
det=0
C=X
for d in dub:
	if C<K:
		det+=d
		C+=1
	elif uni[-1]+2*X-1<=d:
		uni.pop()
		X-=1
		det+=d
print(sum(uni)+det+X**2)

