from itertools import permutations
inf=10**9
n,m,R=map(int,input().split())
r=list(map(int,input().split()))
rr=permutations(r,R)
dis=[[inf]*n for _ in range(n)]
for i in range(m):
	a,b,c=map(int,input().split())
	dis[a-1][b-1]=c
	dis[b-1][a-1]=c
for i in range(n):
	for j in range(n):
		for k in range(n):
			dis[j][k]=min(dis[j][i]+dis[i][k],dis[j][k])
ans=10**12
for x in rr:
	e=0
	for i in range(R-1):
		e+=dis[x[i+1]-1][x[i]-1]
	ans=min(ans,e)
print(ans)
