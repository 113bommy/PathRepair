import sys
input=sys.stdin.readline
def dfs(x,k=0):
	vis[x]=1
	for v in g[x]:
		if vis[v]==0:
			#print(v)
			k=1+dfs(v,k)
	#print(x,'...')
	return k

for _ in range(int(input())):
#	n=int(input())
	n,x=map(int,input().split())
#	s=input().strip()
#	a=list(map(int,input().split()))
	g=[[] for i in range(n+1)]
	for i in range(n-1):
		u,v=map(int,input().split())
		g[u].append(v)
		g[v].append(u)
	vis=[0]*(n+1)
	vis[x]=1
	if len(g[x])<=1:print("Ayush");continue
	c=dfs(x)
#	print(c)
	if c%2==0:print('Ashish')
	else:print('Ayush')