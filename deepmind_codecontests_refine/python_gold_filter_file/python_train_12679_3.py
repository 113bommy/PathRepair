def warshall_floyd(d):
	for k in range(n):
		for i in range(n):
			for j in range(n):
				d[i][j]=min(d[i][j],d[i][k]+d[k][j])
	return d
n,m,l=map(int,input().split())
d=[[10**10 for _ in range(n)]for _ in range(n)]
for i in range(n):
	d[i][i]=0
for i in range(m):
	a,b,c=map(int,input().split())
	d[a-1][b-1]=c
	d[b-1][a-1]=c
p=[[10**5 for _ in range(n)]for _ in range(n)]
d=warshall_floyd(d)
for i in range(n):
	for j in range(n):
		if d[i][j]<=l:
			p[i][j]=1
p=warshall_floyd(p)
q=int(input())
for i in range(q):
	s,t=map(int,input().split())
	if p[s-1][t-1]==10**5:
		print(-1)
		continue
	print(p[s-1][t-1]-1)

