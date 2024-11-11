m,n=map(int,input().split())
se=[]
c=[]
for i in range(m):
	se.append(list(map(str,input().split())))
for j in range(n):
	c.append(list(map(str,input().split())))
for t in range(n):
	for g in range(m):
		if(c[t][1][:-1]==se[g][1]):
			print(' '.join(c[t]),'#'+se[g][0])

