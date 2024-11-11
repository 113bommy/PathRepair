t=int(input())

for _ in range(t):
	n,x=map(int,input().split())
	adj={}
	ht=[1e9]*(n+1)
	ht[x]=0
	for i in range(1,n+1):
		adj[i]=[]
	for i in range(n-1):
		u,v=map(int,input().split())
		adj[u].append(v)
		adj[v].append(u)
	leaf_nodes=[]
	for i in range(1,n+1):
		if len(adj[i])<=1:
			leaf_nodes.append(i)
	def get_dist(s,h):
		ht[s]=min(ht[s],h)
		if ht[s]==h:
			for i in adj[s]:
				get_dist(i,ht[s]+1)
		return
	ht_leaf_nodes=[]
	get_dist(x,0)
	for i in leaf_nodes:
		ht_leaf_nodes.append(ht[i])
	if x in leaf_nodes:
		print('Ayush')
	else:
		s=sum(ht_leaf_nodes)
		if (n-1)%2==0:
			print('Ashish')
		else:
			print('Ayush')
