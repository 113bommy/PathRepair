from collections import defaultdict

n = int(input())
degree = [0 for i in range(n+1)]

def BFS(d,x,visited):

	visited[x] = 1
	queue = [(x,1)]

	l1 = set()
	l2 = set()

	while len(queue):
		temp,j = queue.pop()
		visited[temp] = 1
		if j%2 == 1:
			l1.add(temp)
		else:
			l2.add(temp)
		for i in d[temp]:

			if visited[i] == 0:
				queue.append((i,j+1))
	return l1,l2


d = defaultdict(list)
for i in range(n-1):

	u,v = map(int,input().split())
	d[u].append(v)
	d[v].append(u)

	degree[u] = degree[u] + 1
	degree[v] = degree[v] + 1
visited = [0 for i in range(n+1)]
l1,l2 = BFS(d,1,visited)
s = 0
for i in range(1,n+1):

	if i in l1:
		s = s + len(l2)-degree[i]
	elif i in l2:
		s = s + len(l1)-degree[i]

print(s//2)