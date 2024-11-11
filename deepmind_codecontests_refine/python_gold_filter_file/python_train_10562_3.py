import sys


class Node:

	def __init__(self, id):
		self.id = id
		self.adjacent = set()
		self.visited = 0

	def addEdge(self, edge):
		self.adjacent.add(edge)





class Graph:

	def __init__(self, numNodes, startNode):
		self.nodes = list()
		self.startNode = startNode
		self.result = 0
		self.dfslist = list()
		for num in range(1, numNodes + 1):
			tempNode = Node(num)
			self.nodes.append(tempNode)


	def dfs(self, node):
		if node.visited:
			return
		node.visited = True
		self.dfslist.append(node.id)
		for n in node.adjacent:
			self.dfs(g.findNode(n))


	# finds the number of separate connected components of the graph
	def numConnectedComponents(self):
		s = set()
		result = 0
		for n in self.nodes:
			oldsize = len(s)
			self.addAllAdjacentVertices(n, s)
			if len(s) is not oldsize:
				result += 1
		return result

	# recursively adds a vertex and all connected vertices
	def addAllAdjacentVertices(self, node, set):
		set.add(node.id)
		self.findNode(node.id).visited = 1
		for edge in node.adjacent:
			if self.findNode(edge).visited is not 1:
				self.addAllAdjacentVertices(self.findNode(edge), set)

	# kickoff method that uses a recursive helper method
	def numNodesReachable(self, node):
		return self.nodesHelper(node, 0)

	# helper method to find the number of nodes reachable within the given maximum path length
	def nodesHelper(self, currNode, numSteps):
		self.result += 1
		currNode.visited = 1
		for edge in currNode.adjacent:
			if self.findNode(edge).visited is not 1:
				self.nodesHelper(self.findNode(edge), numSteps + 1)
		return self.result

	# clears the visited field of every node
	def clearVisited(self):
		for node in self.nodes:
			node.visited = 0
		self.result = 0
		self.dfslist.clear()

	def findNode(self, id):
		for node in self.nodes:
			if id == node.id:
				return node

	def findPath(self):
		stack = list()
		answer = list()
		stack.append(self.findNode(self.startNode))
		while len(stack) != 0:
			v = stack[len(stack) - 1]
			if len(v.adjacent) == 0:
				answer.append(v.id)
				stack.pop()
			else:
				edge = v.adjacent.pop()
				self.findNode(edge).adjacent.remove(v.id)
				stack.append(self.findNode(edge))


		return answer


















line = sys.stdin.readline().rstrip()
temp = line.split(" ")
numRows = int(temp[0])
numCols = int(temp[1])

g = Graph(numRows * numCols, 1)

line2 = sys.stdin.readline().rstrip()
line3 = sys.stdin.readline().rstrip()
rl = list(line2)
ud = list(line3)
# rl determiend by row number
# ud determined by col number

for row in range(0, numRows):
	for col in range(0, numCols):
		nodeNumber = row * numCols + col + 1
		node = g.findNode(nodeNumber)

		if rl[row] == '>':
			if col + 1 < numCols:
				dest = row * numCols + col + 2
				node.addEdge(dest)
		else:
			if col - 1 >= 0:
				dest = row * numCols + col
				node.addEdge(dest)

		if ud[col] == '^':
			if row - 1 >= 0:
				dest = (row - 1) * numCols + col + 1
				node.addEdge(dest)
		else:
			if row + 1 < numRows:
				dest = (row + 1) * numCols + col + 1
				node.addEdge(dest)

# for node in g.nodes:
# 	for edge in node.adjacent:
# 		print(str(node.id) + " - " + str(edge))


weGood = True

g.dfs(g.findNode(1))
for n in range(1, numRows * numCols + 1):
	if n not in g.dfslist:
		weGood = False
		break

if not weGood:
	print("NO")
else:
	g.clearVisited()
	g.dfs(g.findNode(numRows * numCols))
	for n in range(1, numRows * numCols + 1):
		if n not in g.dfslist:
			weGood = False
			break
			
	if weGood:
		print("YES")
	else:
		print("NO")

