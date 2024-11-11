from itertools import*

n,m,o=map(int,input().split())
*R,=map(int,input().split())
INF=float("inf")
d=[[INF]*n for _ in range(n)]
r=range
for i in r(n):
	d[i][i]=0
for _ in r(m):
	a,b,c=map(int,input().split())
	d[a-1][b-1]=d[b-1][a-1]=c
for k in r(n):
	for i in r(n):
		for j in r(n):
			d[i][j]=min(d[i][j],d[i][k]+d[k][j])
v=[[d[i-1][j-1]for j in R]for i in R]
m=INF
for t in permutations(r(o)):
	a=0;f=1
	for i,j in zip(t,t[1:]):
		if v[i][j]==INF:
			f=0
			break
		else:
			a+=v[i][j]
	if f:
		m=min(m,a)
print(m)