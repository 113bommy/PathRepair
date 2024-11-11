n,m=map(int,input().split())

gr=[[] for i in range(n)]

for i in range(m):
	u,v=map(int,input().split())
	gr[v-1].append(u-1)
	gr[u-1].append(v-1)

v=[False for i in range(n)]
s=[0]
tr={}
tr[0]=0
while s:
	x=s.pop()
	v[x]=True
	for j in gr[x]:
		if v[j]:continue
		s.append(j)
		tr[j]=tr[x]+1
va=0
ma=0
for j in tr.keys():
	if ma<tr[j]:
		ma=tr[j]
		va=j
v=[False for i in range(n)]
s=[va]
tr={}
tr[va]=0
while s:
	x=s.pop()
	v[x]=True
	for i in gr[x]:
		if v[i]:continue
		s.append(i)
		tr[i]=tr[x]+1
print(max(tr.values()))