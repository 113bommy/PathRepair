def e(x,y,d):
	while y>=0 and x<m:
		d[p[y][x]]=(d[p[y][x]]+1) if p[y][x] in d else 1
		d[q[y][x]],x,y=((d[q[y][x]]-1) if q[y][x] in d else -1),x+1,y-1
	for k in d:
		if d[k]!=0:
			print("NO")
			raise SystemExit()
n,m=map(int,input().split())
p,q=[list(map(int,input().split())) for _ in range(n)],[list(map(int,input().split())) for _ in range(n)]
for i in range(n):e(0,i,{})
for i in range(m):a,b=(e(i,n-1,{}),print("YES")) if i==m-1 else (e(i,n-1,{}),None)