n=int(input())
a=list(map(int, input().split()))

k=set()
b=0
ind={}
for i in a:
	if i not in k:
		k.add(i)
		ind[i]=b
		b+=1
l=set()
occ1=0
ans=1
s=[-1 for i in set(a)]
for i in range(n):
	if a[i] in l:
		j=ind[a[i]]
		s[j]+=1
	else:
		s[ind[a[i]]]=1
		l.add(a[i])

	an=set(s)-set([-1])
	if len(an)==2:
		p=[i for i in an]
		p1=s.count(p[0])
		p2=s.count(p[1])
		if p1==1:
			if p[0]==p[1]+1 or p[0]==1:ans=i+1
		if p2==1:
			if p[1]==p[0]+1 or p[1]==1:ans=i+1
			
	elif len(an)==1:
		p=[i for i in an]
		p1=s.count(p[0])
		if p[0]==1 or p1==1:
			ans=i+1

print(ans)