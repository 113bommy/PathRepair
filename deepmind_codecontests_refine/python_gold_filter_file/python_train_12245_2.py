class Graph:
	def __init__(self,v):
		self.v = v
		self.visited = [False for _ in range(v)]
		self.array = [ [] for _ in range(v)]
	
	def addEdge(self,u,v):	
		self.array[u].append(v)
		self.array[v].append(u)

def solve():
	n = int(input())
	g = Graph(n)
	
	for i in range(n-1):
		u,v = list(map(int,input().split()))
		g.addEdge(u-1,v-1)
	
	queue = [0]
	g.visited[0] = True
	cnt = len(queue)
	nodes_odd  = 0
	nodes_even = 1
	level = 0
	
	while queue:
		parent = queue.pop(0)
		g.visited[parent] = True
		cnt -= 1
		for i in range(len(g.array[parent])):
			if not g.visited[g.array[parent][i]]:
				queue.append(g.array[parent][i])
			
		if cnt == 0 and not len(queue)==0:
			level += 1
			if level%2 == 0:
				nodes_even += len(queue)
			else:
				nodes_odd += len(queue)
			cnt = len(queue)
	
	ans = (nodes_even * nodes_odd)
	
	ans = ans - (n-1)
	print(ans)
		
if __name__ == "__main__":
	solve()